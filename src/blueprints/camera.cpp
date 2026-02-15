#include "../core/time.h"
#include "../platform/window/window.h"
#include "camera.h"
#include <glm/ext/vector_float3.hpp>
#include <glm/mat4x4.hpp>
#include <glm/trigonometric.hpp>
#include <iostream>

#include <GLFW/glfw3.h>
#include "../platform/input/mouse.h"

Camera::Camera(glm::vec3 position, glm::vec2 rotation, int fov){

  this->rotation = rotation;
  this->position = position;      

  float pitch = glm::radians(rotation.x);
  float yaw   = glm::radians(rotation.y);

  this->forward.x = cos(yaw) * cos(pitch);
  this->forward.y = sin(pitch);
  this->forward.z = sin(yaw) * cos(pitch);
  this->forward = glm::normalize(this->forward);
} 

void Camera::Update(){
  sinceMoved++; 

  this->rotation.y = (this->rotation.y+500*mouse::direction.x*Time::deltaTime);
  this->rotation.x = (this->rotation.x+500*mouse::direction.y*Time::deltaTime);
  if (std::abs(mouse::direction.x) > 0 || std::abs(mouse::direction.y) > 0) {
    sinceMoved = 1; 
  } 
  if (this->rotation.x > 89.0f)  this->rotation.x = 89.0f;
  if (this->rotation.x < -89.0f) this->rotation.x = -89.0f;

  float pitch = glm::radians(rotation.x);
  float yaw   = glm::radians(rotation.y);

  this->forward.x = cos(yaw) * cos(pitch);
  this->forward.y = sin(pitch);
  this->forward.z = sin(yaw) * cos(pitch);
  this->forward = glm::normalize(this->forward);

  this->right = glm::normalize(glm::cross(this->forward, worldUp)); 
  this->up = glm::normalize(glm::cross(this->forward, this->right)); 




//  std::system("clear");
//  std::cout <<"X:"<< this->rotation.x <<" Y:"<< this->rotation.y << std::endl;
//  std::cout << "forward:" <<  this->forward.x << " " << 
//                              this->forward.y << " " << 
//                              this->forward.z << std::endl;
//  std::cout << "right:" <<  this->right.x << " " << 
//                              this->right.y << " " << 
//                              this->right.z << std::endl;
//  std::cout << "position:" <<  this->position.x << " " << 
//                              this->position.y << " " << 
//                              this->position.z << std::endl;



}
void Camera::Move(){

  if (glfwGetKey(window::window, GLFW_KEY_W) == GLFW_PRESS){ this->position += this->forward*(Time::deltaTime*3); sinceMoved = 1;}
  if (glfwGetKey(window::window, GLFW_KEY_S) == GLFW_PRESS){ this->position -= this->forward*(Time::deltaTime*3);  sinceMoved = 1;}
  if (glfwGetKey(window::window, GLFW_KEY_A) == GLFW_PRESS){ this->position -= this->right*(Time::deltaTime*3); sinceMoved = 1;}
  if (glfwGetKey(window::window, GLFW_KEY_D) == GLFW_PRESS){ this->position += this->right*(Time::deltaTime*3); sinceMoved = 1;}
}
