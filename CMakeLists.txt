cmake_minimum_required(VERSION 3.31)
project(VxTracer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(glfw3 3.3 REQUIRED)

add_subdirectory(src/app)
add_subdirectory(src/platform/window)
add_subdirectory(libs/glad)
add_subdirectory(src/core/utils)
add_subdirectory(src/renderer)

target_link_libraries(${PROJECT_NAME} engine screen_tex shader_tools window glfw glad render)
 
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

