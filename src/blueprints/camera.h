#pragma once

#include <glm/ext/vector_float3.hpp>
#include <glm/mat4x4.hpp>
#include <glm/trigonometric.hpp>
#include <iostream>
#include "../platform/input/mouse.h"

class Camera{
  private:
    glm::mat4 rotationMatrix;
    glm::vec3 worldUp{0.0f,1.0f,0.0f};

  public:
    int sinceMoved = 1;
    glm::vec3 position{0.f,0.f,0.f};
    glm::vec2 rotation{0.f,0.f};
    
    glm::vec3 forward{0.f,0.f,-1.f};
    glm::vec3 right{1.f,0.f,0.f};
    glm::vec3 up{0.f,1.f,0.f};

    int fov = 80;

    Camera(glm::vec3 position, glm::vec2 rotation, int fov);

    void Update();

    void Move();

};




