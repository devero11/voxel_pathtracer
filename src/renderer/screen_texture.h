#pragma once

#include "../../libs/glad/glad.h"
#include "../scenes/scene.h"

namespace screen_tex {
  
  extern GLuint tex; 

  extern GLuint shader; 

  extern Scene* scene;

  void screenTextureCreate(GLuint& tex, int width, int height);

  void computeTexture(GLuint& tex, int width, int height, GLuint& shader);
}
