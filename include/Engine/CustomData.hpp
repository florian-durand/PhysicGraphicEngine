#pragma once

#include <Engine/ShaderVertex.hpp>
#include <vector>
#include <Meshes/Cube.hpp>
#include <Objects/Object.hpp>

class CustomData
{
public:
    const uint32_t WINDOW_WIDTH = 800;
    const uint32_t WINDOW_HEIGHT = 600;
    const int MAX_FRAMES_IN_FLIGHT = 2;
    Object object = Object(Cube::generateMesh());
};