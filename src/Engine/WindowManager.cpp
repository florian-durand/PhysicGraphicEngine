#include <Engine/WindowManager.hpp>
#include <stdexcept>

void WindowManager::framebufferResizeCallback(GLFWwindow *window, int width, int height)
{
    auto app = reinterpret_cast<WindowManager *>(glfwGetWindowUserPointer(window));
    app->framebufferResized = true;
}

void mouse_callback(GLFWwindow *window, double xpos, double ypos)
{
    static float lastX = 0;
    static float lastY = 0;
    static bool firstMouse = true;

    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = ypos - lastY;

    lastX = xpos;
    lastY = ypos;

    float sensitivity = 0.01f;
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    Camera *camera = static_cast<Camera *>(glfwGetWindowUserPointer(window));
    if (camera)
    {
        camera->rotate(xoffset, -yoffset);
    }
}

void WindowManager::initWindow(Camera &camera)
{
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

    window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Vulkan", nullptr, nullptr);
    glfwSetWindowUserPointer(window, this);
    glfwSetFramebufferSizeCallback(window, framebufferResizeCallback);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetWindowUserPointer(window, &camera);
    glfwSetCursorPosCallback(window, mouse_callback);
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
    Camera *camera = static_cast<Camera *>(glfwGetWindowUserPointer(window));
    while (!glfwWindowShouldClose(window))
    {
        float x = 0, y = 0;
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        {
            glfwSetWindowShouldClose(window, true);
        }
        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        {
            x += 1;
        }
        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        {
            x += -1;
        }
        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        {
            y += -1;
        }
        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        {
            y += 1;
        }
        camera->move(x, y);
        glfwPollEvents();
    }
}