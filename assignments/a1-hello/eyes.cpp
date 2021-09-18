#include "atkui/framework.h"

using namespace glm;
class Eyes : public atkui::Framework
{
  public:
    Eyes() : atkui::Framework(atkui::Orthographic) {
    }

    virtual void setup() {
        thetaRate = 1.5;
        theta = 0;
    }

    virtual void scene() {
        
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
        theta += thetaRate * dt();
        setColor(vec3(0, 0, 0));
        double px = 48 * sin(theta);
        double py = height() * 0.5;
        double a1radius = 50;
        drawSphere(vec3(125+px, py, 0), a1radius);

        double s1 = 48 * sin(theta);
        double q1 = height() * 0.5;
        drawSphere(vec3(375+s1, q1, 0), a1radius);

    }
        float theta;
        float thetaRate;
};

int main(int argc, char** argv) {
  Eyes viewer;
  viewer.run();
  return 0;
}
