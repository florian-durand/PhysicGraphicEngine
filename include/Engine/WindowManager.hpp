#define GLFW_INCLUDE_VULKAN
#define VK_USE_PLATFORM_WIN32_KHR
#include <GLFW/glfw3.h>
#define GLFW_EXPOSE_NATIVE_WIN32
#include <GLFW/glfw3native.h>

#include <functional>
#include <Engine/Camera.hpp>

class WindowManager
{
public:
    void initWindow(Camera &camera);

    static void framebufferResizeCallback(GLFWwindow *window, int width, int height);

    void destroyWindow();

    void createSurface(VkInstance &instance, VkSurfaceKHR &surface);

    bool isFrameBufferResized();

    void getFramebufferSize(int &width, int &height);

    void setFramebufferResized(bool state);

    void PollEventsWhileWindowOpened();

private:
    const uint32_t WINDOW_WIDTH = 800;
    const uint32_t WINDOW_HEIGHT = 600;
    GLFWwindow *window;
    bool framebufferResized = false;
    VkSurfaceKHR surface;
};