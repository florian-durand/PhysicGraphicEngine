#pragma once
#include <Meshes/Mesh.hpp>
#include <Meshes/Transformation.hpp>

class Object
{
public:
    Object(Mesh _mesh);

    Mesh &getMesh();

    Transformation &getTransformation();

private:
    Mesh mesh;
    Transformation tranformation;
};