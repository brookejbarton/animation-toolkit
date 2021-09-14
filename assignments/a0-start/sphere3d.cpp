#include "atkui/framework.h"

using glm::vec3;

class Sphere3D : public atkui::Framework {
 public:
  Sphere3D() : atkui::Framework(atkui::Perspective) {
  }

  virtual void setup() {
      pos = vec3(0, 0, 0);
      vel = vec3(100,10,0);
      space = false;
  }
  
  virtual void scene() {
    if (space == true) {
      pos = pos + vel * dt();
    }
    else {
      pos = vec3(0, 0, 0);
    }

    // colors are RGB triplets in range [0,1]
    setColor(vec3(0,1,0));

    // draw a sphere at center of the world
    float radius = 50.0;
    drawSphere(pos, radius);
    
  }

  void keyUp(int key, int mods) {
      if (key == GLFW_KEY_SPACE) {
          space = true;
      }
      else if (key == GLFW_KEY_R) {
          space = false;
      }
  }
  
  vec3 pos;
  vec3 vel;
  bool space;
};

int main(int argc, char** argv)
{
  Sphere3D viewer;
  viewer.run();
  return 0;
}
