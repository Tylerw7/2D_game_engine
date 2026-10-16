add_library(engine STATIC
  core/Window.cpp
  core/Input.cpp)
target_include_directories(engine PUBLIC ${CMAKE_SOURCE_DIR}/src)
target_link_libraries(engine PUBLIC glfw glad)