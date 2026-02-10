#include "mouse.h"
#include <GLFW/glfw3.h>
#include <glm/ext/vector_float2.hpp>
#include <glm/vec2.hpp>

bool firstMouse = true;
double lastX = 800.0f / 2.0f;  // Set to half your window width
double lastY = 600.0f / 2.0f;  // Set to half your window height
glm::vec2 mouse::direction(0,0);

void mouse_callback(GLFWwindow* window, double xpos, double ypos) {
    if (firstMouse) {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    // Calculate the movement since the last frame
    double xoffset = xpos - lastX;
    double yoffset = lastY - ypos; // Reversed: y-coords go from bottom to top

    lastX = xpos;
    lastY = ypos;

    float sensitivity = 0.1f;
    xoffset *= sensitivity;
    yoffset *= sensitivity;
    mouse::direction.x = xoffset;
    mouse::direction.y = yoffset; 
    

}


void mouse::lock(GLFWwindow *window){
  glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

  if (glfwRawMouseMotionSupported())
    glfwSetInputMode(window, GLFW_RAW_MOUSE_MOTION, GLFW_TRUE);

  glfwSetCursorPosCallback(window, mouse_callback);
}



