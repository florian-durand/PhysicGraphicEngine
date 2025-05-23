#pragma once

#define GLFW_INCLUDE_VULKAN
#define VK_USE_PLATFORM_WIN32_KHR
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <array>

class ShaderVertex
{
public:
	glm::vec3 pos;
	glm::vec3 color;
	glm::vec3 normal;

	static VkVertexInputBindingDescription getBindingDescription();

	static std::array<VkVertexInputAttributeDescription, 3> getAttributeDescriptions();
};