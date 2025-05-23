#include <Meshes/Mesh.hpp>
#include <Meshes/Cube.hpp>

void Mesh::addVertex(glm::vec3 position, glm::vec3 color, glm::vec3 normal)
{
    vertices.emplace_back(ShaderVertex{position, color, normal});
}

void Mesh::addTriangleFan(uint16_t index1, uint16_t index2, uint16_t index3)
{
    indices.emplace_back(index1);
    indices.emplace_back(index2);
    indices.emplace_back(index3);
}

std::vector<ShaderVertex> &Mesh::getVertices()
{
    return vertices;
}

const ShaderVertex *Mesh::getVerticesData()
{
    return vertices.data();
}

std::size_t Mesh::getVerticesSize()
{
    return vertices.size();
}

std::vector<uint16_t> &Mesh::getIndices()
{
    return indices;
}

uint16_t *Mesh::getIndicesData()
{
    return indices.data();
}

std::size_t Mesh::getIndicesSize()
{
    return indices.size();
}

ULONGLONG Mesh::getVertexDataSize()
{
    return sizeof(vertices[0]);
}

ULONGLONG Mesh::getIndexDataSize()
{
    return sizeof(indices[0]);
}

void Mesh::flipNormals()
{
    for (int i = 0; i < indices.size(); i += 3)
    {
        indices[i] = indices[i + 1];
        indices[i + 1] = indices[i];
    }
}