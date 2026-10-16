#pragma once

struct GLFWwindow;


class Input {
    public:
      explicit Input(GLFWwindow* window);

      bool isKeyPressed(int key) const;

    private:
      GLFWwindow* m_window;  
};