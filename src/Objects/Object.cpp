#include <Objects/Object.hpp>

Object::Object(Mesh _mesh) : mesh(_mesh)
{
}

Mesh &Object::getMesh()
{
    return mesh;
}

Transformation &Object::getTransformation()
{
    return tranformation;
}