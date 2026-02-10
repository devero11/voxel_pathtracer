#include "screen_texture.h"
#include "../core/utils/shader_tools.h"


GLuint screen_tex::tex;

GLuint screen_tex::shader;

void screen_tex::screenTextureCreate(GLuint& tex, int width, int height){

  //CREATE SHADER PROGRAM
  GLuint computeShader = shader_tools::compileShader("../../src/shaders/screen.comp", GL_COMPUTE_SHADER);
  screen_tex::shader = glCreateProgram();
  glAttachShader(screen_tex::shader, computeShader);
  glLinkProgram(screen_tex::shader);

  //TEXTURE GENERATE
  glGenTextures(1, &tex);
  glBindTexture(GL_TEXTURE_2D, tex);
  glTexStorage2D(GL_TEXTURE_2D, 1, GL_RGBA8, width,height);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

void screen_tex::computeTexture(GLuint& tex, int width, int height, GLuint& shader){
  glUseProgram(screen_tex::shader);
  glBindImageTexture(0, tex, 0, GL_FALSE, 0, GL_WRITE_ONLY, GL_RGBA8);
  glDispatchCompute((width+15)/16, (height+15)/16, 1);
  glMemoryBarrier(GL_SHADER_IMAGE_ACCESS_BARRIER_BIT);
}
