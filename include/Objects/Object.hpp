#pragma once
#include <Meshes/Mesh.hpp>
#include <Meshes/Meshes.hpp>
#include <Meshes/Transformation.hpp>

class Object
{
public:
    Meshes &getMeshes();

    void addMesh(Mesh mesh);

    Transformation &getTransformation();

    void setVertexOffset(VkDeviceSize vertexOffset);

    void setIndexOffset(VkDeviceSize indexOffset);

    void setTotalIndexCount(uint32_t totalIndexCount);

    void draw(float delta, size_t index, VkBuffer &vertexBuffer, VkBuffer &indexBuffer, VkCommandBuffer &commandBuffer, float width, float height, void *uboPtr, VkPipelineLayout &pipelineLayout, VkDescriptorSet &descriptorSet);

private:
    Meshes meshes;
    Transformation tranformation;
    VkDeviceSize vertexOffset;
    VkDeviceSize indexOffset;
    uint32_t totalIndexCount;
};