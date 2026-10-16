#include "engine/core/Window.hpp"
#include "engine/core/Input.hpp"
#include <glad/gl.h>
#include <GLFW/glfw3.h>

int main() {
    Window window(800, 600, "Engine");

    Input input(window.handle());

    while (!window.shouldClose()) {
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);  // dark gray
        glClear(GL_COLOR_BUFFER_BIT);
        window.pollEvents();

        if (input.isKeyPressed(GLFW_KEY_ESCAPE))
          glfwSetWindowShouldClose(window.handle(), true);

        window.swapBuffers();
    }
}