#pragma once

#include <vector>
#include <Meshes/Mesh.hpp>

class Meshes
{
private:
    std::vector<Mesh> meshes;

public:
    void addMesh(Mesh &mesh);

    std::vector<Mesh> &getMeshesList();
};
