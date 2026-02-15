#pragma once

#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "../../../libs/glad/glad.h"



namespace shader_tools{
  
  std::string loadShaderSource(const std::string& filepath);


  GLuint compileShader(const std::string& path, GLenum type);

  void logGPUChunk(GLuint textureID, int w, int h, int d) ;
} 
