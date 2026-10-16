#include "engine/core/Input.hpp"
#include <GLFW/glfw3.h>


Input::Input(GLFWwindow* window): m_window(window){}

bool Input::isKeyPressed(int key) const{
    return glfwGetKey(m_window, key) == GLFW_PRESS;
}