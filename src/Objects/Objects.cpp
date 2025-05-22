#include <Objects/Objects.hpp>
#include <glm/gtc/matrix_transform.hpp>

size_t Objects::previousVertexOffset = 0;
size_t Objects::previousIndexOffset = 0;
std::chrono::_V2::system_clock::time_point Objects::lastTime = std::chrono::high_resolution_clock::now();

void Objects::addObject(Object object, VkBuffer &vertexBuffer, VkBuffer &indexBuffer, VkBuffer &stagingBuffer, void *mappedStagingPtr, VkCommandPool &commandPool, VkDevice &device, VkQueue graphicsQueue)
{
    // look how to implement vertex offset to keep track of new objects
    Object &objectRef = objects.emplace_back(object);
    VkDeviceSize vertexOffset = 0;
    uint32_t vertexCount = 0;

    for (Mesh &mesh : objectRef.getMeshes().getMeshesList())
    {
        memcpy(mappedStagingPtr, mesh.getVerticesData(), mesh.getVerticesSize() * mesh.getVertexDataSize());
        vertexCount += mesh.getVerticesSize();
        vertexOffset += mesh.getVerticesSize() * mesh.getVertexDataSize();
    }
    VkCommandBufferAllocateInfo allocInfo{};
    allocInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
    allocInfo.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
    allocInfo.commandPool = commandPool;
    allocInfo.commandBufferCount = 1;

    VkCommandBuffer commandBuffer;
    vkAllocateCommandBuffers(device, &allocInfo, &commandBuffer);

    VkCommandBufferBeginInfo beginInfo{};
    beginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
    beginInfo.flags = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT;

    vkBeginCommandBuffer(commandBuffer, &beginInfo);

    VkBufferCopy copyRegion{};
    copyRegion.srcOffset = 0;                             // Optional
    copyRegion.dstOffset = Objects::previousVertexOffset; // Optional
    copyRegion.size = vertexOffset;
    vkCmdCopyBuffer(commandBuffer, stagingBuffer, vertexBuffer, 1, &copyRegion);

    vkEndCommandBuffer(commandBuffer);

    VkSubmitInfo submitInfo{};
    submitInfo.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
    submitInfo.commandBufferCount = 1;
    submitInfo.pCommandBuffers = &commandBuffer;

    vkQueueSubmit(graphicsQueue, 1, &submitInfo, VK_NULL_HANDLE);
    vkQueueWaitIdle(graphicsQueue);
    vkFreeCommandBuffers(device, commandPool, 1, &commandBuffer);

    objectRef.setVertexOffset(previousVertexOffset);

    size_t indexOffset = 0;
    size_t indexCount = 0;
    for (Mesh &mesh : objectRef.getMeshes().getMeshesList())
    {
        memcpy(mappedStagingPtr, mesh.getIndicesData(), mesh.getIndicesSize() * mesh.getIndexDataSize());
        indexCount += mesh.getIndicesSize();
        indexOffset += mesh.getIndicesSize() * mesh.getIndexDataSize();
    }
    allocInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
    allocInfo.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
    allocInfo.commandPool = commandPool;
    allocInfo.commandBufferCount = 1;

    vkAllocateCommandBuffers(device, &allocInfo, &commandBuffer);

    beginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
    beginInfo.flags = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT;

    vkBeginCommandBuffer(commandBuffer, &beginInfo);

    copyRegion.srcOffset = 0;                            // Optional
    copyRegion.dstOffset = Objects::previousIndexOffset; // Optional
    copyRegion.size = indexOffset;
    vkCmdCopyBuffer(commandBuffer, stagingBuffer, indexBuffer, 1, &copyRegion);

    vkEndCommandBuffer(commandBuffer);

    submitInfo.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
    submitInfo.commandBufferCount = 1;
    submitInfo.pCommandBuffers = &commandBuffer;

    vkQueueSubmit(graphicsQueue, 1, &submitInfo, VK_NULL_HANDLE);
    vkQueueWaitIdle(graphicsQueue);
    vkFreeCommandBuffers(device, commandPool, 1, &commandBuffer);

    objectRef.setIndexOffset(previousIndexOffset);

    previousVertexOffset += vertexOffset;
    previousIndexOffset += indexOffset;
    objectRef.setTotalIndexCount(indexCount);
}

void Objects::drawAll(glm::mat4 view, VkBuffer &vertexBuffer, VkBuffer &indexBuffer, VkCommandBuffer &commandBuffer, float width, float height, void *uboPtr, VkPipelineLayout &pipelineLayout, VkDescriptorSet &descriptorSet)
{
    auto currentTime = std::chrono::high_resolution_clock::now();
    float delta = std::chrono::duration<float, std::chrono::seconds::period>(currentTime - lastTime).count();
    lastTime = currentTime;

    glm::mat4 projectionMatrix, PVMatrix;
    projectionMatrix = glm::perspective(glm::radians(45.0f), width / height, 0.1f, 10.0f);
    projectionMatrix[1][1] *= -1;
    PVMatrix = projectionMatrix * view; // projectionMatrix * glm::lookAt(glm::vec3(3.0f, 0.0f, 3.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f));

    size_t index = 0;

    for (Object &object : objects)
    {
        object.draw(delta, PVMatrix, index, vertexBuffer, indexBuffer, commandBuffer, width, height, uboPtr, pipelineLayout, descriptorSet);
        index++;
    }
}