#pragma once

#include <GLFW/glfw3.h>
#include <glm/vec2.hpp>


namespace mouse {
  extern glm::vec2 direction;  

  void setup(GLFWwindow* window); 
}
