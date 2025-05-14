#pragma once

#define GLFW_INCLUDE_VULKAN
#define VK_USE_PLATFORM_WIN32_KHR
#include <GLFW/glfw3.h>
#define GLFW_EXPOSE_NATIVE_WIN32
#include <GLFW/glfw3native.h>

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <vector>
#include <map>
#include <optional>
#include <set>
#include <cstdint>
#include <limits>
#include <algorithm>
#include <fstream>
#include <glm/glm.hpp>
#include <array>
#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <ShaderVertex.hpp>
#include <CustomData.hpp>
#include <UniformBufferObject.hpp>

#include <chrono>

VkResult CreateDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkDebugUtilsMessengerEXT *pDebugMessenger)
{
    auto func = (PFN_vkCreateDebugUtilsMessengerEXT)vkGetInstanceProcAddr(instance, "vkCreateDebugUtilsMessengerEXT");
    if (func != nullptr)
    {
        return func(instance, pCreateInfo, pAllocator, pDebugMessenger);
    }
    else
    {
        return VK_ERROR_EXTENSION_NOT_PRESENT;
    }
}

void DestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT debugMessenger, const VkAllocationCallbacks *pAllocator)
{
    auto func = (PFN_vkDestroyDebugUtilsMessengerEXT)vkGetInstanceProcAddr(instance, "vkDestroyDebugUtilsMessengerEXT");
    if (func != nullptr)
    {
        func(instance, debugMessenger, pAllocator);
    }
}

static std::vector<char> readFile(const std::string &filename)
{
    std::ifstream file(filename, std::ios::ate | std::ios::binary);

    if (!file.is_open())
    {
        throw std::runtime_error("failed to open file!");
    }

    size_t fileSize = (size_t)file.tellg();
    std::vector<char> buffer(fileSize);

    file.seekg(0);
    file.read(buffer.data(), fileSize);

    file.close();

    return buffer;
}

class HelloTriangleApplication
{
public:
    void run();

private:
    // Initialize glfw window
    void initWindow();

    static void framebufferResizeCallback(GLFWwindow *window, int width, int height);

    // Initialize Vulkan
    void initVulkan();

    void createDescriptorSets();

    void createDescriptorPool();

    void createUniformBuffers();

    void createDescriptorSetLayout();

    void createIndexBuffer();

    void createBuffer(VkDeviceSize size, VkBufferUsageFlags usage, VkMemoryPropertyFlags properties, VkBuffer &buffer, VkDeviceMemory &bufferMemory);

    void createVertexBuffer();

    void recreateSwapChain();

    void cleanupSwapChain();

    void copyBuffer(VkBuffer srcBuffer, VkBuffer dstBuffer, VkDeviceSize size);

    uint32_t findMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties);

    void createSyncObjects();

    void createCommandBuffer();

    void recordCommandBuffer(VkCommandBuffer commandBuffer, uint32_t imageIndex);

    void createCommandPool();

    void createFramebuffers();

    void createRenderPass();

    void createGraphicsPipeline();

    VkShaderModule createShaderModule(const std::vector<char> &code);

    void createImageViews();

    void createSwapChain();

    void createSurface();

    void createLogicalDevice();

    struct SwapChainSupportDetails;

    SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);

    void pickPhysicalDevice();

    struct QueueFamilyIndices;

    QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);

    bool isDeviceSuitable(VkPhysicalDevice device);

    VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR> &availableFormats);

    VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR> &availablePresentModes);

    VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR &capabilities);

    bool checkDeviceExtensionSupport(VkPhysicalDevice device);

    void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT &createInfo);

    void setupDebugMessenger();

    // Create Vulkan instance
    void createInstance();

    void checkExtensionsValidity(const std::vector<const char *> &glfwExtensions, const std::vector<VkExtensionProperties> &extensions);

    static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
        VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
        VkDebugUtilsMessageTypeFlagsEXT messageType,
        const VkDebugUtilsMessengerCallbackDataEXT *pCallbackData,
        void *pUserData);

    void mainLoop();

    void drawFrame();

    void updateUniformBuffer(uint32_t currentImage);

    void cleanup();

    bool checkValidationLayerSupport();

    std::vector<const char *> getRequiredExtensions();

    GLFWwindow *window;
    VkInstance instance;
    VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
    VkDevice device;
    VkQueue graphicsQueue;
    VkDebugUtilsMessengerEXT debugMessenger;
    VkSurfaceKHR surface;
    VkQueue presentQueue;
    VkSwapchainKHR swapChain;
    std::vector<VkImage> swapChainImages;
    VkFormat swapChainImageFormat;
    VkExtent2D swapChainExtent;
    std::vector<VkImageView> swapChainImageViews;
    VkRenderPass renderPass;
    VkDescriptorSetLayout descriptorSetLayout;
    VkPipelineLayout pipelineLayout;
    VkPipeline graphicsPipeline;
    std::vector<VkFramebuffer> swapChainFramebuffers;
    VkCommandPool commandPool;
    std::vector<VkCommandBuffer> commandBuffers;
    std::vector<VkSemaphore> imageAvailableSemaphores;
    std::vector<VkSemaphore> renderFinishedSemaphores;
    std::vector<VkFence> inFlightFences;
    VkBuffer vertexBuffer;
    VkDeviceMemory vertexBufferMemory;
    VkBuffer indexBuffer;
    VkDeviceMemory indexBufferMemory;
    std::vector<VkBuffer> uniformBuffers;
    std::vector<VkDeviceMemory> uniformBuffersMemory;
    std::vector<void *> uniformBuffersMapped;
    VkDescriptorPool descriptorPool;
    std::vector<VkDescriptorSet> descriptorSets;
    uint32_t currentFrame = 0;
    bool framebufferResized = false;
    const std::vector<const char *> validationLayers = {
        "VK_LAYER_KHRONOS_validation"};
    const std::vector<const char *> deviceExtensions = {
        VK_KHR_SWAPCHAIN_EXTENSION_NAME};
    CustomData data;

#ifdef NDEBUG
    const bool enableValidationLayers = false;
#else
    const bool enableValidationLayers = true;
#endif
};