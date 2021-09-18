#include "atkui/framework.h"

using namespace glm;

class Look : public atkui::Framework {
 public:
  Look() : atkui::Framework(atkui::Orthographic) {
  }

  virtual void setup() {
    pressed = false;
  }
  
  virtual void scene() {
    double a1radius = 50;
    
    if (pressed == true) {
        pos = mousePosition();
        setColor(vec3(1, 0, 0));
        drawSphere(vec3(pos[0], height() - pos[1],0), 15);
    }

    //whites of the eyes
    setColor(vec3(1, 1, 1));
    double a = width() * 0.25;
    double b = height() * 0.5;
    double aradius = 150;
    drawSphere(vec3(a, b, -100), aradius);

    double s = width() * 0.75;
    double q = height() * 0.5;
    drawSphere(vec3(s, q, -100), aradius);

    //pupils
    setColor(vec3(0, 0, 0));

    leftAngle = atan2((pos[1] - (height() * 0.5)), (pos[0] - (width() * 0.25)));
    left_pupilX = (width() * 0.25) + cos(leftAngle) * (a1radius-10);
    left_pupilY = (height() * 0.5) + sin(leftAngle) * (a1radius-10);
    drawSphere(vec3(left_pupilX, height() - left_pupilY, 0), a1radius);

    rightAngle = atan2((pos[1] - height() * 0.5), (pos[0] - width() * 0.75));
    right_pupilX = (width() * 0.75) + cos(rightAngle) * (a1radius-10);
    right_pupilY = (height() * 0.5) + sin(rightAngle) * (a1radius-10);
    drawSphere(vec3(right_pupilX, height() - right_pupilY, 0), a1radius);
  }

  void mouseDown(int button, int mods) {
      if (button == GLFW_MOUSE_BUTTON_LEFT){
          pressed = true;
      }
  }

  void mouseUp(int button, int mods) {
      if (button == GLFW_MOUSE_BUTTON_LEFT) {
          pressed = false;
      }
  }

 private:
     vec2 pos;
     bool pressed;
     int left_pupilX;
     int left_pupilY;
     int right_pupilX;
     int right_pupilY;
     int leftAngle;
     int rightAngle;
};

int main(int argc, char** argv) {
  Look viewer;
  viewer.run();
  return 0;
}
