#pragma once

#include <glm/glm.hpp>

class Transformation
{
public:
    void setScale(glm::vec3 newScale);

    void setLocation(glm::vec3 newLocation);

    void setRotation(glm::vec3 newRotation);

    void move(glm::vec3 movement);

    void rotate(glm::vec3 rotation);

    void scale(glm::vec3 scaling);

    glm::mat4 getTransformationMatrix();

private:
    glm::vec3 location = glm::vec3(0);
    glm::vec3 rotation = glm::vec3(0);
    glm::vec3 scaleValue = glm::vec3(1);
};