#include "render.h"

GLuint render::VAO;

GLuint render::screenTriangleInit(){

  GLuint vertexShader = shader_tools::compileShader("../../src/shaders/screen.vert", GL_VERTEX_SHADER);
  GLuint fragmentShader = shader_tools::compileShader("../../src/shaders/screen.frag", GL_FRAGMENT_SHADER);

  GLuint shaderProgram = glCreateProgram();
  glAttachShader(shaderProgram, vertexShader);
  glAttachShader(shaderProgram, fragmentShader);
  glLinkProgram(shaderProgram);


  glGenVertexArrays(1, &VAO);
  glBindVertexArray(VAO);

  return shaderProgram;
}


void render::screenTriangleRender(GLuint shader, GLuint& tex){
  
  glUseProgram(shader);
  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_2D, tex);
  glBindVertexArray(VAO);
  glDrawArrays(GL_TRIANGLES, 0, 3);
}


