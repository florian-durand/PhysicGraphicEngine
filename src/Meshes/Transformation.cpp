#define GLM_ENABLE_EXPERIMENTAL

#include <Meshes/Transformation.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>

void Transformation::setScale(glm::vec3 newScale)
{
    scale = newScale;
}

void Transformation::setLocation(glm::vec3 newLocation)
{
    location = newLocation;
}

void Transformation::setRotation(glm::vec3 newRotation)
{
    newRotation[0] = glm::clamp<glm::f32>(newRotation[0], 0, 360);
    newRotation[1] = glm::clamp<glm::f32>(newRotation[1], 0, 360);
    newRotation[2] = glm::clamp<glm::f32>(newRotation[2], 0, 360);
}

glm::mat4 Transformation::getTransformationMatrix()
{
    glm::vec3 radianRotation = glm::radians(rotation);
    glm::mat4 mat = glm::translate(glm::mat4(1.0f), location);
    mat *= glm::eulerAngleXYZ(rotation.x, rotation.y, rotation.z);
    mat = glm::scale(mat, scale);

    return mat;
}