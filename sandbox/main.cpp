#include "engine/core/Window.hpp"
#include <glad/gl.h>

int main() {
    Window window(800, 600, "Engine");
    while (!window.shouldClose()) {
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);  // dark gray
        glClear(GL_COLOR_BUFFER_BIT);
        window.pollEvents();
        window.swapBuffers();
    }
}