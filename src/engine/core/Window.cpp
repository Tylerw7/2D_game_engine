#include "engine/core/Window.hpp"
#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <stdexcept>

Window::Window(int width, int height, const std::string& title) {
    if (!glfwInit()) throw std::runtime_error("glfwInit failed");

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    if (!m_window) { glfwTerminate(); throw std::runtime_error("create failed"); }

    glfwMakeContextCurrent(m_window);
    if (!gladLoadGL(glfwGetProcAddress))
      throw std::runtime_error("glad failed");
}

Window::~Window() {
    if (m_window) glfwDestroyWindow(m_window);
    glfwTerminate();
}

bool Window::shouldClose() const { return glfwWindowShouldClose(m_window); }
void Window::pollEvents()        { glfwPollEvents(); }
void Window::swapBuffers()       { glfwSwapBuffers(m_window); }