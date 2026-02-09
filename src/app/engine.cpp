#include "engine.h"

GLuint engine::triangle;

void engine::Render(int width, int height, GLuint triangle){
  
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  screen_tex::computeTexture(screen_tex::tex, width, height, screen_tex::shader);
  render::screenTriangleRender(triangle,screen_tex::tex);

}


GLuint engine::Setup(int width, int height, const char *title){

  window::window = window::initWindow(width, height, title);

  GLuint triangle = render::screenTriangleInit();
  screen_tex::screenTextureCreate(screen_tex::tex, width, height);

  return triangle;

}
