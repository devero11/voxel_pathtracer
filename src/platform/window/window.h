#pragma once


#include "../../../libs/glad/glad.h"
#include <GLFW/glfw3.h>

namespace window{
  extern GLFWwindow* window;

  GLFWwindow* initWindow(int width, int height, const char* title); 

  void framebuffer_size_callback(GLFWwindow* window, int width, int height);
}
