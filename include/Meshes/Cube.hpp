#pragma once

#include <vector>
#include <Engine/ShaderVertex.hpp>
#include <Meshes/Mesh.hpp>

class Cube
{
public:
    static Mesh generateMesh()
    {
        Mesh mesh;
        mesh.addVertex({0, 0, 0}, {0, 0, 0});
        mesh.addVertex({1, 0, 0}, {1, 0, 0});
        mesh.addVertex({0, 1, 0}, {0, 1, 0});
        mesh.addVertex({1, 1, 0}, {1, 1, 0});
        mesh.addVertex({0, 0, 1}, {0, 0, 1});
        mesh.addVertex({1, 0, 1}, {1, 0, 1});
        mesh.addVertex({0, 1, 1}, {0, 1, 1});
        mesh.addVertex({1, 1, 1}, {1, 1, 1});
        mesh.addTriangleFan(0, 4, 2);
        mesh.addTriangleFan(2, 4, 6);
        mesh.addTriangleFan(1, 3, 5);
        mesh.addTriangleFan(3, 7, 5);
        mesh.addTriangleFan(2, 6, 3);
        mesh.addTriangleFan(3, 6, 7);
        mesh.addTriangleFan(0, 1, 4);
        mesh.addTriangleFan(4, 1, 5);
        mesh.addTriangleFan(0, 2, 1);
        mesh.addTriangleFan(1, 2, 3);
        mesh.addTriangleFan(4, 5, 6);
        mesh.addTriangleFan(6, 5, 7);
        return mesh;
    };
};