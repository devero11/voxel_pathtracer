#include "time.h" 
#include <chrono>

float Time::deltaTime = 0;
auto lastTime = std::chrono::high_resolution_clock::now();
auto currentTime = std::chrono::high_resolution_clock::now();

void Time::calculateDeltaTime(){
   currentTime = std::chrono::high_resolution_clock::now();

   std::chrono::duration<float> elapsed = currentTime - lastTime;
   Time::deltaTime = elapsed.count();

   lastTime = currentTime;
}
