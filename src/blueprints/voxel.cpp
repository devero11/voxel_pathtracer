#include "voxel.h"
#include <algorithm>
#include <cstring>
#include <iostream>
#include <ostream>
#include <sys/types.h>
#include <vector>
#include <fstream>

std::vector<unsigned char> loadBytes(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary | std::ios::ate);
    
    if (!file.is_open()) return {}; 

    std::streamsize size = file.tellg();
    file.seekg(0, std::ios::beg); // Reset to beginning to read

    std::vector<unsigned char> buffer(size);
    if (file.read(reinterpret_cast<char*>(buffer.data()), size)) {
        return buffer;
    }

    return {};
}


Chunk::Chunk(){
  this->voxels = new u_int8_t[64*64*64];
  this->width = 64;
  this->length = 64;
  this->depth = 64;

  std::fill(this->voxels, this->voxels + (width * length * depth), 1);
  
std::vector<u_int8_t> loadedData = loadBytes("chunk.save");

if (!loadedData.empty()) {
    

    std::memcpy(this->voxels, loadedData.data(), 64*64*64);
    
}
}

Chunk::Chunk(int width, int length, int depth, glm::vec3 pos){
  this->voxels = new u_int8_t[width*length*depth]();
  this->width = width;
  this->length = length;
  this->depth = depth;
  std::fill(this->voxels, this->voxels + (width * length * depth), 1);
  this->position = pos;
}


Chunk::~Chunk(){
  delete[] this->voxels;
}
