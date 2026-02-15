#pragma once

#include "../blueprints/camera.h"
#include "../blueprints/voxel.h"

class Scene{
  public:
    
    Camera* activeCamera; 
    Chunk chunk;

    Scene(Camera* activeCamera);
};
