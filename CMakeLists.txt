cmake_minimum_required(VERSION 3.20)
project(Engine LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# DGLFW download
include(FetchContent)
FetchContent_Declare(glfw
  GIT_REPOSITORY https://github.com/glfw/glfw.git
  GIT_TAG 3.4)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(glfw)

# GLAD as its own small library
add_library(glad external/glad/src/gl.c)
target_include_directories(glad PUBLIC external/glad/include)

add_subdirectory(src/engine)
add_subdirectory(sandbox)