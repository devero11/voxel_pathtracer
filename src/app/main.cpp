#include "../core/time.h"
#include "../platform/window/window.h"
#include "engine.h"
#include "../blueprints/camera.h"
#include "../scenes/scene.h"
#include <glm/ext/vector_float2.hpp>
#include <glm/ext/vector_float3.hpp>

#include <chrono>
#include <thread>

const int WIDTH = 1200;
const int HEIGHT = 800;
const char* TITLE = "vxTracer"; 




int main(int argc, const char * argv[]){

  glm::vec3 pos(0,0,0);
  glm::vec2 rot(0,0);
  Camera camera(pos, rot, 80);

  Scene scene(&camera); 

  screen_tex::scene = &scene;

  engine::triangle = engine::Setup(WIDTH, HEIGHT,TITLE);
  
  glfwSwapInterval(0);
  while(!glfwWindowShouldClose(window::window)){
    Time::calculateDeltaTime();         

  
    engine::Render(WIDTH, HEIGHT, engine::triangle);
    glfwSwapBuffers(window::window);
    glfwPollEvents();  

    (scene.activeCamera)->Update();
    (scene.activeCamera)->Move();

  }


  return 0;
}
