#pragma once

#include "../../libs/glad/glad.h"
#include "../renderer/render.h"
#include "../renderer/screen_texture.h"
#include "../platform/window/window.h"


namespace engine {
  extern GLuint triangle;


  GLuint Setup(int width, int height, const char* title);
  void Render(int width, int height, GLuint triangle);
}
