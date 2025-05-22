#pragma once

#include <Meshes/Transformation.hpp>
#include <glm/gtc/matrix_transform.hpp>
class Camera
{
public:
    Camera()
    {
        updateUnitVectors();
    }

    void rotate(glm::f32 xOffset, glm::f32 yOffset)
    {
        yaw += xOffset;
        pitch += yOffset;
        if (pitch > 89.0f)
            pitch = 89.0f;
        if (pitch < -89.0f)
            pitch = -89.0f;

        updateUnitVectors();
    }

    void move(float x, float y)
    {

        float moveSpeed = 0.00001;
        glm::vec3 forwardVector = front * x * moveSpeed;
        glm::vec3 rightVector = right * y * moveSpeed;
        position += forwardVector + rightVector;
    }

    glm::mat4 getTransformationMatrix()
    {
        return glm::lookAt(position, position + front, up);
    }

    void updateUnitVectors()
    {
        // calculate the new Front vector
        front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
        front.y = sin(glm::radians(pitch));
        front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
        front = glm::normalize(front);
        right = glm::normalize(glm::cross(front, worldUp));
        up = glm::normalize(glm::cross(right, front));
    }

private:
    float yaw = -90.0f;
    float pitch = 0.0f;
    glm::vec3 position = glm::vec3({0, 0, 2});
    glm::vec3 front = glm::vec3(0);
    glm::vec3 right = glm::vec3(0);
    glm::vec3 up = glm::vec3(0);
    glm::vec3 worldUp = glm::vec3(0, 1, 0);
};