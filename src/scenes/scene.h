#pragma once

#include "../blueprints/camera.h"
#include "../blueprints/voxel.h"
#include <vector>

class Scene{
  public:
    unsigned int selectedVoxel = 1; 

    Camera* activeCamera; 
    Chunk chunk;

    Scene(Camera* activeCamera);

    void Update(GLFWwindow* window);


    void saveBytes(const std::string& filename, unsigned char* data, size_t size);
};
