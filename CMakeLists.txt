cmake_minimum_required(VERSION 3.31)
project(VxTracer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)




find_package(glfw3 3.3 REQUIRED)
find_package(glm REQUIRED)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    ${CMAKE_SOURCE_DIR}/src/*.cpp
    ${CMAKE_SOURCE_DIR}/libs/glad.c
)

message(STATUS "SOURCES: ${SOURCES}")


add_executable(VxTracer src/app/main.cpp ${SOURCES})

target_link_libraries(${PROJECT_NAME}  glm::glm glfw )


set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
