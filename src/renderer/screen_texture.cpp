#include "screen_texture.h"
#include "../core/utils/shader_tools.h"
#include <GL/gl.h>
#include <cmath>
#include <glm/ext/vector_float3.hpp>
#include <glm/trigonometric.hpp>
#include <iostream>
#include <ostream>
#include <vector>


GLuint screen_tex::tex;
GLuint screen_tex::shader;

Scene* screen_tex::scene;

GLuint chunk_data;


GLuint acum;

GLint posLoc;
GLint dirLoc;
GLint horLoc;
GLint verLoc;

GLint frameLoc;

int frameCount = 1;
float halfHeight;
float halfWidth;
float aspectRatio;

glm::vec3 Horizontal;
glm::vec3 Vertical;

void screen_tex::screenTextureCreate(GLuint& tex, int width, int height){

  aspectRatio = static_cast<float>(width)/height; 
  float fovDegrees = (screen_tex::scene)->activeCamera->fov;
  float fovRadians = fovDegrees * (3.14159265f / 180.0f);
  halfHeight = std::tan(fovRadians / 2.0f);
  halfWidth = halfHeight*aspectRatio;


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

  //ACUMULATOR
  glGenTextures(1, &acum);
  glBindTexture(GL_TEXTURE_2D, acum);
  glTexStorage2D(GL_TEXTURE_2D, 1, GL_RGBA32F, width,height);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);



  //LOAD CHUNK
  glGenTextures(1, &chunk_data);
  glBindTexture(GL_TEXTURE_3D, chunk_data);
  glTexStorage3D(GL_TEXTURE_3D, 1, GL_R8UI, (screen_tex::scene)->chunk.width,
                                            (screen_tex::scene)->chunk.length,
                                            (screen_tex::scene)->chunk.depth);

  glPixelStorei(GL_UNPACK_ALIGNMENT, 1); 
  glTexSubImage3D(GL_TEXTURE_3D, 0, 0, 0, 0, (screen_tex::scene)->chunk.width,
                                             (screen_tex::scene)->chunk.length,
                                             (screen_tex::scene)->chunk.depth, GL_RED_INTEGER, GL_UNSIGNED_BYTE, (screen_tex::scene)->chunk.voxels);


  glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
  glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
  glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_BORDER);

  float borderColor[] = { 0.0f, 0.0f, 0.0f, 0.0f };
  glTexParameterfv(GL_TEXTURE_3D, GL_TEXTURE_BORDER_COLOR, borderColor);

  //LOAD UNIFORMS
  posLoc = glGetUniformLocation(screen_tex::shader, "camPos");
  dirLoc = glGetUniformLocation(screen_tex::shader, "camForward");
  horLoc = glGetUniformLocation(screen_tex::shader, "Horizontal");
  verLoc = glGetUniformLocation(screen_tex::shader, "Vertical");

  frameLoc = glGetUniformLocation(screen_tex::shader, "u_frame_count");
}

void screen_tex::computeTexture(GLuint& tex, int width, int height, GLuint& shader){
  frameCount = screen_tex::scene->activeCamera->sinceMoved;

  Horizontal = screen_tex::scene->activeCamera->right*(halfWidth*2);
  Vertical = screen_tex::scene->activeCamera->up*(halfHeight*2);

  glUseProgram(screen_tex::shader);
  glBindImageTexture(0, tex, 0, GL_FALSE, 0, GL_READ_WRITE, GL_RGBA8);

  glBindImageTexture(2, acum, 0, GL_FALSE, 0, GL_READ_WRITE, GL_RGBA32F);
       
  glUniform3fv(posLoc, 1,&((screen_tex::scene)->activeCamera->position[0]));
  glUniform3fv(dirLoc, 1,&((screen_tex::scene)->activeCamera->forward[0]));
  glUniform3fv(horLoc, 1,&Horizontal[0]);
  glUniform3fv(verLoc, 1,&Vertical[0]);
  glUniform1i(frameLoc, frameCount);

 // glBindImageTexture(1, chunk_data, 0, GL_FALSE, 0, GL_READ_ONLY, GL_R8UI);
 // glBindTexture(GL_TEXTURE_3D, acum);
 //
  glActiveTexture(GL_TEXTURE1);
  glBindTexture(GL_TEXTURE_3D, chunk_data);

  glDispatchCompute((width+15)/16, (height+15)/16, 1);
  glMemoryBarrier(GL_SHADER_IMAGE_ACCESS_BARRIER_BIT);

  }

