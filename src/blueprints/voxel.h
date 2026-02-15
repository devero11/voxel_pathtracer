#pragma once

#include <glm/ext/vector_float3.hpp>
#include <sys/types.h>


class Chunk{
  private:

  public:
    glm::vec3 position{0.f,0.f,0.f};
    int width, length, depth;
    u_int8_t* voxels;

    Chunk();
    Chunk(int width, int length, int depth, glm::vec3 pos);
    ~Chunk();
};
