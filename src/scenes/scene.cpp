#include "scene.h"
#include "../blueprints/camera.h"
#include <GLFW/glfw3.h>
#include <glm/common.hpp>
#include <glm/ext/vector_float3.hpp>
#include <iostream>
#include <vector>
#include <cstdint>
#include <fstream>


void Scene::saveBytes(const std::string& filename, unsigned char* data, size_t size) {
    std::ofstream file(filename, std::ios::binary);
    if (file.is_open()) {
        file.write(reinterpret_cast<const char*>(data), size);
        file.close();
    }
}


Scene::Scene(Camera* activeCamera){
      this->activeCamera = activeCamera;  
}

bool laststate = false;
bool laststateLeft = false;


void Scene::Update(GLFWwindow* window){
    bool currentState = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS;
    if (currentState && !laststate)
    {
      glm::vec3 currentPos = activeCamera->position+activeCamera->forward*0.2f;
      glm::vec3 index = glm::floor(currentPos);
      for(int i =0; i<100; i++){

        if(chunk.voxels[static_cast<int>(index.x + chunk.length*(index.y + (index.z*chunk.depth)))] >0){

          chunk.voxels[static_cast<int>(index.x + chunk.length*(index.y + (index.z*chunk.depth)))] = 0; 

          activeCamera->sinceMoved = 0;
          saveBytes("chunk.save", chunk.voxels, 64*64*64);
          break;
        }
        currentPos = currentPos+activeCamera->forward*0.2f;
        index = glm::floor(currentPos);

      }
    }
    bool currentStateLeft = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;
    if (currentStateLeft && !laststateLeft)
    {
      glm::vec3 currentPos = activeCamera->position+activeCamera->forward*0.2f;
      glm::vec3 index = glm::floor(currentPos);
      for(int i =0; i<100; i++){

        if(chunk.voxels[static_cast<int>(index.x + chunk.length*(index.y + (index.z*chunk.depth)))] >0){
          currentPos = currentPos-activeCamera->forward*0.2f;
          index = glm::floor(currentPos);
          chunk.voxels[static_cast<int>(index.x + chunk.length*(index.y + (index.z*chunk.depth)))] = selectedVoxel; 
          activeCamera->sinceMoved = 0;
          saveBytes("chunk.save", chunk.voxels, 64*64*64);
          break;
        }
        currentPos = currentPos+activeCamera->forward*0.2f;
        index = glm::floor(currentPos);

      }
    }

    laststate = currentState;
    laststateLeft = currentStateLeft;


    if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS){ selectedVoxel = 1; }
    if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS){ selectedVoxel = 2;}
    if (glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS){ selectedVoxel = 3;}

    if (glfwGetKey(window, GLFW_KEY_4) == GLFW_PRESS){ selectedVoxel = 4;}
    if (glfwGetKey(window, GLFW_KEY_5) == GLFW_PRESS){ selectedVoxel = 5;}
    if (glfwGetKey(window, GLFW_KEY_9) == GLFW_PRESS){ selectedVoxel = 10;}
    if (glfwGetKey(window, GLFW_KEY_0) == GLFW_PRESS){ selectedVoxel = 11;}

    if (glfwGetKey(window, GLFW_KEY_8) == GLFW_PRESS){ selectedVoxel = 12;}
    
    

}
