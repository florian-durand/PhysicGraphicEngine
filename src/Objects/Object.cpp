#include <Objects/Object.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <Engine/RenderApplication.hpp>

Meshes &Object::getMeshes()
{
    return meshes;
}

Transformation &Object::getTransformation()
{
    return tranformation;
}

void Object::addMesh(Mesh mesh)
{
    meshes.addMesh(mesh);
}

void Object::setVertexOffset(VkDeviceSize vertexOffset)
{
    this->vertexOffset = vertexOffset;
}

void Object::setIndexOffset(VkDeviceSize indexOffset)
{
    this->indexOffset = indexOffset;
}

void Object::setTotalIndexCount(uint32_t totalIndexCount)
{
    this->totalIndexCount = totalIndexCount;
}

void Object::draw(float delta, glm::mat4 &PVMatrix, size_t index, VkBuffer &vertexBuffer, VkBuffer &indexBuffer, VkCommandBuffer &commandBuffer, float width, float height, void *uboPtr, VkPipelineLayout &pipelineLayout, VkDescriptorSet &descriptorSet)
{

    tranformation.rotate({0, 0, delta * 2});

    uint32_t dynamicOffset = index * sizeof(UniformBufferObject);

    UniformBufferObject ubo{};

    ubo.mvp = PVMatrix * tranformation.getTransformationMatrix();

    memcpy((char *)uboPtr + dynamicOffset, &ubo, sizeof(ubo));

    vkCmdBindDescriptorSets(commandBuffer, VK_PIPELINE_BIND_POINT_GRAPHICS, pipelineLayout, 0, 1, &descriptorSet, 1, &dynamicOffset);

    VkBuffer vertexBuffers[] = {vertexBuffer};
    VkDeviceSize offsets[] = {vertexOffset};
    vkCmdBindVertexBuffers(commandBuffer, 0, 1, vertexBuffers, offsets);

    vkCmdBindIndexBuffer(commandBuffer, indexBuffer, indexOffset, VK_INDEX_TYPE_UINT16);

    vkCmdDrawIndexed(commandBuffer, static_cast<uint32_t>(totalIndexCount), 1, 0, 0, 0);
}