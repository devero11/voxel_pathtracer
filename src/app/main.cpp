#include "../platform/window/window.h"
#include "engine.h"


const int WIDTH = 800;
const int HEIGHT = 600;
const char* TITLE = "vxTracer"; 



int main(int argc, const char * argv[]){

  engine::triangle = engine::Setup(WIDTH, HEIGHT,TITLE);

  while(!glfwWindowShouldClose(window::window)){
    
    engine::Render(WIDTH, HEIGHT, engine::triangle);
    
    glfwSwapBuffers(window::window);
    glfwPollEvents();  
  }

  return 0;
}
