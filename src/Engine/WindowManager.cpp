#include <Engine/WindowManager.hpp>
#include <stdexcept>

void WindowManager::framebufferResizeCallback(GLFWwindow *window, int width, int height)
{
    auto app = reinterpret_cast<WindowManager *>(glfwGetWindowUserPointer(window));
    app->framebufferResized = true;
}

void WindowManager::initWindow()
{
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

    window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Vulkan", nullptr, nullptr);
    glfwSetWindowUserPointer(window, this);
    glfwSetFramebufferSizeCallback(window, framebufferResizeCallback);
}

void WindowManager::destroyWindow()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}

void WindowManager::createSurface(VkInstance &instance, VkSurfaceKHR &surface)
{
    if (glfwCreateWindowSurface(instance, window, nullptr, &surface) != VK_SUCCESS)
    {
        throw std::runtime_error("failed to create window surface!");
    }
}

bool WindowManager::isFrameBufferResized()
{
    return framebufferResized;
}

void WindowManager::getFramebufferSize(int &width, int &height)
{
    glfwGetFramebufferSize(window, &width, &height);
    glfwPollEvents();
}

void WindowManager::setFramebufferResized(bool state)
{
    framebufferResized = state;
}

void WindowManager::PollEventsWhileWindowOpened()
{
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
    }
}