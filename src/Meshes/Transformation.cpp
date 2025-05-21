#define GLM_ENABLE_EXPERIMENTAL

#include <Meshes/Transformation.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>
#include <iostream>

glm::f32 clampRotation(glm::f32 rotation)
{
    if (rotation < 0)
    {
        return glm::mod((360.0 + rotation), 360.0);
    }
    else if (rotation > 360.0)
    {
        return glm::mod((rotation - 360.0), 360.0);
    }
    return rotation;
}

void Transformation::setScale(glm::vec3 newScale)
{
    scaleValue = newScale;
}

void Transformation::setLocation(glm::vec3 newLocation)
{
    location = newLocation;
}

void Transformation::setRotation(glm::vec3 newRotation)
{
    rotation[0] = clampRotation(newRotation[0]);
    rotation[1] = clampRotation(newRotation[1]);
    rotation[2] = clampRotation(newRotation[2]);
}

void Transformation::move(glm::vec3 movement)
{
    location += movement;
}

void Transformation::rotate(glm::vec3 rotation)
{
    this->rotation += rotation;
    this->rotation[0] = clampRotation(this->rotation[0]);
    this->rotation[1] = clampRotation(this->rotation[1]);
    this->rotation[2] = clampRotation(this->rotation[2]);
}

void Transformation::scale(glm::vec3 scaling)
{
    scaleValue += scaling;
}

glm::mat4 Transformation::getTransformationMatrix()
{
    glm::vec3 radianRotation = glm::radians(rotation);
    glm::mat4 mat = glm::translate(glm::mat4(1.0f), location);
    mat *= glm::eulerAngleXYZ(rotation.x, rotation.y, rotation.z);
    mat = glm::scale(mat, scaleValue);

    return mat;
}