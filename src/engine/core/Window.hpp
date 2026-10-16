#pragma once
#include <string>
struct GLFWwindow;


class Window {
    public:
      Window(int width, int height, const std::string& title);
      ~Window();
      Window(const Window&) = delete;            // one owner of the pointer
      Window& operator=(const Window&) = delete;

      bool shouldClose() const;
      void pollEvents();
      void swapBuffers();

      GLFWwindow* handle() const;

    private:
      GLFWwindow* m_window = nullptr;  
};