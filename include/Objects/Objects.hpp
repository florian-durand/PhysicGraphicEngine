#pragma once

#include <vector>
#include <Objects/Object.hpp>
#include <chrono>

class Objects
{

public:
    void addObject(Object object, VkBuffer &vertexBuffer, VkBuffer &indexBuffer, VkBuffer &stagingBuffer, void *mappedStagingPtr, VkCommandPool &commandPool, VkDevice &device, VkQueue graphicsQueue);

    void drawAll(glm::mat4 view, VkBuffer &vertexBuffer, VkBuffer &indexBuffer, VkCommandBuffer &commandBuffer, float width, float height, void *uboPtr, VkPipelineLayout &pipelineLayout, VkDescriptorSet &descriptorSet);

private:
    std::vector<Object> objects;
    std::vector<ShaderVertex> vertices;
    std::vector<uint16_t> indices;
    static size_t previousVertexOffset;
    static size_t previousIndexOffset;
    static std::chrono::_V2::system_clock::time_point lastTime;
};