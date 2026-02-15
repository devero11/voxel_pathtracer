#include "voxel.h"
#include <algorithm>
#include <iostream>
#include <sys/types.h>

Chunk::Chunk(){
  this->voxels = new u_int8_t[64];
  this->width = 4;
  this->length = 4;
  this->depth = 4;
}

Chunk::Chunk(int width, int length, int depth, glm::vec3 pos){
  this->voxels = new u_int8_t[width*length*depth]();
  this->width = width;
  this->length = length;
  this->depth = depth;
  //std::fill(this->voxels, this->voxels + (width * length * depth), 1);
  this->position = pos;
}


Chunk::~Chunk(){
  delete this->voxels;
}
