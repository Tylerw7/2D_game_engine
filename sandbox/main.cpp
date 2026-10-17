#include "engine/core/Window.hpp"
#include "engine/core/Input.hpp"
#include "engine/gfx/Shader.hpp"
#include <glad/gl.h>
#include <GLFW/glfw3.h>

int main() {
    Window window(800, 600, "Engine");
    Input input(window.handle());

    // Shader program (reads the two GLSL files, compiles on GPU)
    Shader shader("assets/shaders/basic.vert", "assets/shaders/basic.frag");

    // --- Triangle data, in NDC (center origin, Y up) ---
    float vertices[] = {
        -0.5f, -0.5f, 0.0f,   // bottom left
         0.5f, -0.5f, 0.0f,   // bottom right
         0.0f,  0.5f, 0.0f    // top
    };

    // --- Setup: upload data + describe layout (once) ---
    unsigned int vao, vbo;
    glGenVertexArrays(1, &vao);          // make VAO (the "how to read" recipe)
    glGenBuffers(1, &vbo);               // make VBO (GPU memory for the data)

    glBindVertexArray(vao);              // start recording into this VAO
    glBindBuffer(GL_ARRAY_BUFFER, vbo);  // make vbo active
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // slot 0 = 3 floats per vertex, stride 3 floats, offset 0
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // --- Loop ---
    while (!window.shouldClose()) {
        window.pollEvents();
        if (input.isKeyPressed(GLFW_KEY_ESCAPE))
            glfwSetWindowShouldClose(window.handle(), true);

        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        shader.use();                        // activate shader program
        glBindVertexArray(vao);              // bind the recipe
        glDrawArrays(GL_TRIANGLES, 0, 3);    // draw 3 vertices as a triangle

        window.swapBuffers();
    }
}