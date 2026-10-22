#pragma once
#include <vector>

class Mesh {
public:
    // Takes the vertex floats directly. Each vertex = 3 floats (x, y, z).
    Mesh(const std::vector<float>& vertices);
    ~Mesh();

    Mesh(const Mesh&) = delete;
    Mesh& operator=(const Mesh&) = delete;

    void draw() const;

private:
    unsigned int m_vao = 0;        // vertex array object (the layout recipe)
    unsigned int m_vbo = 0;        // vertex buffer object (the GPU bytes)
    int m_vertexCount = 0;         // how many vertices to draw
};