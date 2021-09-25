#include <iostream>
#include "atkui/framework.h"
using namespace glm;

class Gradient : public atkui::Framework {
 public:
  Gradient() : atkui::Framework(atkui::Orthographic) {
      northWest = vec3(1, 1, 0);
      northEast = vec3(0, 1, 1);
      southWest = vec3(1, 0, 0);
      southEast = vec3(1, 0, 1);
      t = 0;
      tx = 0;
      ty = 0;
  }
  
  virtual void scene() {
      //t += dt(); // can also use elapsedTime 

      float duration = 8.0f;
     
      int incX = 0;
      int incY = 0;
      int timeIncX = 0;
      int timeIncY = 0;

      for (int i = 0; i < 11; ++i) {
          
          for (int j = 0; j < 11; ++j) {
              tx = elapsedTime()/ ((width() - incX)/2);
              ty = elapsedTime()/ ((height() - incY)/2);
              tx = glm::clamp(tx, 0.0f, width()); // clamp to range width of window
              ty = glm::clamp(ty, 0.0f, height());

              vec3 lerp1 = northWest * (1 - tx) + northEast * tx;
              vec3 lerp2 = southWest * (1 - tx) + southEast * tx;
              vec3 finalLerp = lerp1 * (1 - ty) + lerp2 * ty;
              setColor(finalLerp);

              drawCube(vec3(incX-20, (height() - incY)+20, 0), vec3(50, 50, 0));
              incX += 50;
          }
          incY += 50;
          incX = 0;
          timeIncX += 0;
          
      }
  }
    private:
      float t;
      float tx;
      float ty;
      vec3 northWest;
      vec3 northEast;
      vec3 southWest;
      vec3 southEast;
};

int main(int argc, char **argv) {
  Gradient viewer;
  viewer.run();
}
