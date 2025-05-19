#pragma once

#include <glm/glm.hpp>

class Transformation
{
public:
    void setScale(glm::vec3 newScale);

    void setLocation(glm::vec3 newLocation);

    void setRotation(glm::vec3 newRotation);

    glm::mat4 getTransformationMatrix();

private:
    glm::vec3 location = glm::vec3(0);
    glm::vec3 rotation = glm::vec3(0);
    glm::vec3 scale = glm::vec3(1);
};