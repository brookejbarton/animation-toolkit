#include <iostream>
#include "atkui/framework.h"
using namespace glm;

class DrawCubic : public atkui::Framework
{
 public:
  DrawCubic() : atkui::Framework(atkui::Orthographic, 400, 400) {
  }
  virtual void setup() {
      drawBern = false;
      drawCast = false;
  }

  virtual void scene()
  {
     if (drawBern == true) {
         for (float t = 0; t < 1; t += 0.1) {
             vec3 a = Bernstein(t);
             vec3 b = Bernstein(t + 0.1);

             setColor(vec3(0, 0, 1));
             drawLine(a, b);
         }
     }

     if (drawCast == true) {
         for (float t = 0; t < 1; t += 0.1) {
             vec3 a = Casteljau(t);
             vec3 b = Casteljau(t + 0.1);

             setColor(vec3(1, 0, 0));
             drawLine(a, b);
         }
     }
      setColor(vec3(0,0,1));
      drawSphere(B0, 10);
      drawSphere(B3, 10);

      setColor(vec3(1,1,0));
      drawSphere(B1, 10);
      drawSphere(B2, 10);
  }
  vec3 Bernstein(float t) {
      float f1 = pow((1.0f - t), 3.0f);
      float f2 = 3.0f * t * pow((1.0f - t), 2.0f);
      float f3 = 3.0f * pow(t, 2.0f) * (1.0f - t);
      float f4 = pow(t, 3.0f);

      vec3 p = f1 * B0 + f2 * B1 + f3 * B2 + f4 * B3;
      return p;
  }

  vec3 Casteljau(float t) {
      //level 1
      vec3 lerp1 = B0 * (1.0f - t) + B1 * t;
      vec3 lerp2 = B1 * (1.0f - t) + B2 * t;
      vec3 lerp3 = B2 * (1.0f - t) + B3 * t;
      //level 2
      vec3 lerp1_2 = lerp1 * (1.0f - t) + lerp2 * t;
      vec3 lerp2_2 = lerp2 * (1.0f - t) + lerp3 * t;
      //level 3
      vec3 finalLerp = lerp1_2 * (1.0f - t) + lerp2_2 * t;

      return finalLerp;
  }

  void keyUp(int key, int mod) {
    if (key == GLFW_KEY_1) {
        drawBern = true;  
    }
    else if (key == GLFW_KEY_2) {
        drawCast = true;
    } 
  }

 private:
     bool drawBern;
     bool drawCast;
     vec3 B0 = vec3(100,  50, 0);
     vec3 B1 = vec3(150, 200, 0);
     vec3 B2 = vec3(250, 100, 0);
     vec3 B3 = vec3(300, 300, 0);
};

int main(int argc, char **argv) {
  DrawCubic viewer;
  viewer.run();
}
