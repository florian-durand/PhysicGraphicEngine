#include <Meshes/Meshes.hpp>

void Meshes::addMesh(Mesh &mesh)
{
    meshes.emplace_back(mesh);
}

std::vector<Mesh> &Meshes::getMeshesList()
{
    return meshes;
}