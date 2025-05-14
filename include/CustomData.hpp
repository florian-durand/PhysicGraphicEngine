#pragma once

#include <ShaderVertex.hpp>
#include <vector>

class CustomData
{
public:
    const uint32_t WINDOW_WIDTH = 800;
    const uint32_t WINDOW_HEIGHT = 600;
    const int MAX_FRAMES_IN_FLIGHT = 2;

    const std::vector<ShaderVertex> vertices = {
        {{-0.5f, -0.5f}, {1.0f, 0.0f, 0.0f}},
        {{0.5f, -0.5f}, {0.0f, 1.0f, 0.0f}},
        {{0.5f, 0.5f}, {0.0f, 0.0f, 1.0f}},
        {{-0.5f, 0.5f}, {1.0f, 1.0f, 1.0f}}};

    const std::vector<uint16_t> indices = {
        0, 1, 2, 2, 3, 0};
};