#pragma once

#include "../core/utils/shader_tools.h"
#include "../../libs/glad/glad.h"

namespace render {
  
  extern GLuint VAO;

  GLuint screenTriangleInit();
  void screenTriangleRender(GLuint shader,GLuint& tex);
}
