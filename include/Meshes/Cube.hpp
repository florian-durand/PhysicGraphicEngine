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
        mesh.addVertex({-0.5, -0.5, -0.5}, {1, 0, 0}, {0, 0, -1});
        mesh.addVertex({0.5, -0.5, -0.5}, {1, 0, 0}, {0, 0, -1});
        mesh.addVertex({-0.5, 0.5, -0.5}, {1, 0, 0}, {0, 0, -1});
        mesh.addVertex({0.5, 0.5, -0.5}, {1, 0, 0}, {0, 0, -1});
        mesh.addTriangleFan(0, 2, 1);
        mesh.addTriangleFan(1, 2, 3);
        mesh.addVertex({-0.5, -0.5, 0.5}, {1, 0, 0}, {0, 0, 1});
        mesh.addVertex({0.5, -0.5, 0.5}, {1, 0, 0}, {0, 0, 1});
        mesh.addVertex({-0.5, 0.5, 0.5}, {1, 0, 0}, {0, 0, 1});
        mesh.addVertex({0.5, 0.5, 0.5}, {1, 0, 0}, {0, 0, 1});
        mesh.addTriangleFan(4, 5, 6);
        mesh.addTriangleFan(6, 5, 7);
        mesh.addVertex({-0.5, -0.5, -0.5}, {1, 0, 0}, {0, 1, 0});
        mesh.addVertex({0.5, -0.5, -0.5}, {1, 0, 0}, {0, 1, 0});
        mesh.addVertex({-0.5, -0.5, 0.5}, {1, 0, 0}, {0, 1, 0});
        mesh.addVertex({0.5, -0.5, 0.5}, {1, 0, 0}, {0, 1, 0});
        mesh.addTriangleFan(8, 9, 10);
        mesh.addTriangleFan(10, 9, 11);
        mesh.addVertex({-0.5, 0.5, -0.5}, {1, 0, 0}, {0, -1, 0});
        mesh.addVertex({0.5, 0.5, -0.5}, {1, 0, 0}, {0, -1, 0});
        mesh.addVertex({-0.5, 0.5, 0.5}, {1, 0, 0}, {0, -1, 0});
        mesh.addVertex({0.5, 0.5, 0.5}, {1, 0, 0}, {0, -1, 0});
        mesh.addTriangleFan(12, 14, 13);
        mesh.addTriangleFan(13, 14, 15);
        mesh.addVertex({-0.5, -0.5, -0.5}, {1, 0, 0}, {-1, 0, 0});
        mesh.addVertex({-0.5, 0.5, -0.5}, {1, 0, 0}, {-1, 0, 0});
        mesh.addVertex({-0.5, -0.5, 0.5}, {1, 0, 0}, {-1, 0, 0});
        mesh.addVertex({-0.5, 0.5, 0.5}, {1, 0, 0}, {-1, 0, 0});
        mesh.addTriangleFan(16, 18, 17);
        mesh.addTriangleFan(17, 18, 19);
        mesh.addVertex({0.5, -0.5, -0.5}, {1, 0, 0}, {1, 0, 0});
        mesh.addVertex({0.5, 0.5, -0.5}, {1, 0, 0}, {1, 0, 0});
        mesh.addVertex({0.5, -0.5, 0.5}, {1, 0, 0}, {1, 0, 0});
        mesh.addVertex({0.5, 0.5, 0.5}, {1, 0, 0}, {1, 0, 0});
        mesh.addTriangleFan(20, 21, 22);
        mesh.addTriangleFan(22, 21, 23);
        return mesh;
    };
};