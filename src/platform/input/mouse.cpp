#include "mouse.h"
#include <GLFW/glfw3.h>
#include <cmath>
#include <glm/vec2.hpp>

glm::vec2 mouse::direction(0,0);


void mouse_callback(GLFWwindow* window, double xpos, double ypos) {
    int width, height;
    glfwGetWindowSize(window, &width, &height);
    double centerX = width / 2.0;
    double centerY = height / 2.0;

    double xoffset = xpos - centerX;
    double yoffset = centerY - ypos;

    const double DEADZONE = 2;
    if (fabs(xoffset) < DEADZONE) xoffset = 0.0;
    if (fabs(yoffset) < DEADZONE) yoffset = 0.0;

    float sensitivity = 0.1f;
    mouse::direction.x = static_cast<float>(xoffset * sensitivity);
    mouse::direction.y = static_cast<float>(yoffset * sensitivity);

    glfwSetCursorPos(window, centerX, centerY);
}

void mouse::setup(GLFWwindow *window){
    int width, height;

    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    if (glfwRawMouseMotionSupported())
        glfwSetInputMode(window, GLFW_RAW_MOUSE_MOTION, GLFW_TRUE);

    glfwGetWindowSize(window, &width, &height);
    glfwSetCursorPos(window, width/2.0, height/2.0);
    glfwSetCursorPosCallback(window, mouse_callback);
}

