#include "scene.h"
#include "../blueprints/camera.h"


Scene::Scene(Camera* activeCamera){
      this->activeCamera = activeCamera;  
      this->chunk.voxels[32] = 1;
      this->chunk.voxels[33] = 1;

      this->chunk.voxels[36] = 10;
       
      this->chunk.voxels[34] = 11;
      this->chunk.voxels[18] = 1;

      this->chunk.voxels[17] = 1;
      this->chunk.voxels[16] = 1;

      this->chunk.voxels[0] = 1;

      this->chunk.voxels[1] = 1;

      this->chunk.voxels[2] = 1;
      this->chunk.voxels[3] = 1;


      this->chunk.voxels[26] = 3;
      

      this->chunk.voxels[23] = 1;


      this->chunk.voxels[15] = 1;
      this->chunk.voxels[11] = 1;
      this->chunk.voxels[7] = 1;
      this->chunk.voxels[3] = 1;


      this->chunk.voxels[19] = 1;

      this->chunk.voxels[27] = 1;

      this->chunk.voxels[31] = 1;

      this->chunk.voxels[35] = 1;

      this->chunk.voxels[39] = 1;

      this->chunk.voxels[43] = 1;

      this->chunk.voxels[47] = 1;
       


      this->chunk.voxels[63] = 2;
      this->chunk.voxels[62] = 2;
      this->chunk.voxels[61] = 2;
      this->chunk.voxels[60] = 2;
      this->chunk.voxels[59] = 2;
      this->chunk.voxels[58] = 2;
      this->chunk.voxels[57] = 2;

      this->chunk.voxels[56] = 2;
      this->chunk.voxels[55] = 2;
      this->chunk.voxels[54] = 2;
      this->chunk.voxels[53] = 2;
      this->chunk.voxels[52] = 2;

      this->chunk.voxels[51] = 2;
      this->chunk.voxels[50] = 2;
      this->chunk.voxels[49] = 2;
      this->chunk.voxels[48] = 2;

}


