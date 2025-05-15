#pragma once

#include <vector>
#include <glm/glm.hpp>
#include <Engine/ShaderVertex.hpp>

class Mesh
{
public:
    void addVertex(glm::vec3 position, glm::vec3 color);

    void addTriangleFan(uint16_t index1, uint16_t index2, uint16_t index3);

    const ShaderVertex *getVertices();

    std::size_t getVerticesSize();

    uint16_t *getIndices();

    std::size_t getIndicesSize();

    ULONGLONG getVertexDataSize();

    ULONGLONG getIndexDataSize();

    void flipNormals();

private:
    std::vector<ShaderVertex> vertices;
    std::vector<uint16_t> indices;
};