#include "atkui/framework.h"

using namespace glm;

class Unique : public atkui::Framework {
 public:
  Unique() : atkui::Framework(atkui::Orthographic) {
  }

  virtual void setup() {
      thetaRate = 1.5;
      theta = 0;
      thetaSun = 0;
      thetaRateSun = 1.5;
      noseInc = 0;

      size = sizeof(particles) / sizeof(particles[0]);
      for (int i = 0; i < size; ++i) {
          particles[i] = vec3(0, agl::random(0.0f, 9.0f), agl::random(-9.0f, 9.0f));

      }
  }

  virtual void scene() {
      //background
      background(vec3(.49, .73, .91));
      setColor(vec3(1, .86, 0));
      drawSphere(vec3(1, height(), 0), 250);
      setColor(vec3(1, 0, 0));
    

      double aradius = 40; //whites
      double a1radius = 20; //pupils


      ////diglett1
      //whites of the eyes
      setColor(vec3(1, 1, 1));
      double a = width() * 0.20;
      double b = height() * 0.30;
      drawSphere(vec3(a, b, -100), aradius);
      
      double s = width() * 0.35;
      double q = height() * 0.30;
      drawSphere(vec3(s, q, -100), aradius);

      //pupils
      theta += thetaRate * dt();
      setColor(vec3(0, 0, 0));
      double px = 10 * sin(theta);
      double py = height() * 0.3;
      
      drawSphere(vec3(100 + px, py, -50), a1radius);

      double s1 = 10 * sin(theta);
      double q1 = height() * 0.3;
      drawSphere(vec3(175 + s1, q1, 0), a1radius);

      //body
      int c = b - 15;
      setColor(vec3(.2,.03, 0));
      drawSphere(vec3(a + 38, b, -200), 130);
      for (int i = 0; i < 15; ++i) {
          drawSphere(vec3(a + 38, b - 10, -200), 130);
          b = b - 10;
      }
    /* //shadow
      setColor(vec3(.1, .03, 0));
      int shadRad = 130;
      //drawSphere(vec3(a + 48, c, -250), 130);
      for (int i = 0; i < 15; ++i) {
          drawSphere(vec3(a + 43, c, -250), shadRad);
          shadRad += 1.5;
          c = c - 10;
      }*/ 

      //nose
      //setColor(vec3(1, 0, 0));
      int startNose = (width() * .255);
      int noseRad = 20;
      setColor(vec3(.6, .12, .20));
      for (int p = 0; p < 20; ++p) {
          drawSphere(vec3(startNose, height() * .23, -100), noseRad);
          startNose = startNose + 1;
          if (p < 10) {
              noseRad += 1;
          }
          if (p == 17) {
              setColor(vec3(.8, .32, .4));
              drawSphere(vec3(startNose-15, height() * .24, 0), 15);
              setColor(vec3(.6, .12, .20));
          }
          if (p > 10) {
              noseRad -= 1;
          }
      }

      ////diglett2
      //whites of the eyes
      setColor(vec3(1, 1, 1));
      double ab = width() * 0.42;
      double bb = height() * 0.5;
      drawSphere(vec3(ab, bb, -100), aradius);

      double sb = width() * 0.63;
      double qb = height() * 0.5;
      drawSphere(vec3(sb, qb, -100), aradius);

      //pupils
      theta += thetaRate * dt();
      setColor(vec3(0, 0, 0));
      double pxb = 10 * sin(theta);
      double pyb = height() * 0.5;
      drawSphere(vec3(210 + pxb, pyb, 0), a1radius);

      double s1b = 10 * sin(theta);
      double q1b = height() * 0.5;
      drawSphere(vec3(315 + s1b, q1b, 0), a1radius);

      //body
      setColor(vec3(.77, .38, .06));
      drawSphere(vec3(ab + 53, bb, -300), 160);
      for (int j = 0; j < 50; ++j) {
          drawSphere(vec3(ab + 53, bb - 10, -300), 160);
          bb = bb - 10;
      }

      //nose
      //setColor(vec3(1, 0, 0));
      int startNose2 = (width() * .5);
      int noseRad2 = 25;
      setColor(vec3(.6, .12, .20));
      for (int l = 0; l < 24; ++l) {
          drawSphere(vec3(startNose2, height() * .43, -100), noseRad2);
          startNose2 = startNose2 + 1;
          if (l < 12) {
              noseRad2 += 1;
          }
          if (l == 12) {
              setColor(vec3(.8, .32, .4));
              drawSphere(vec3(startNose2 - 15, height() * .44, 0), 15);
              setColor(vec3(.6, .12, .20));
          }
          if (l > 12) {
              noseRad2 -= 1;
          }
      }
      

      ////diglett3
      //whites of the eyes
      setColor(vec3(1, 1, 1));
      double ac = width() * 0.70;
      double bc = height() * 0.38;
      drawSphere(vec3(ac, bc, -100), aradius);

      double sc = width() * .87;
      double qc = height() * 0.38;
      drawSphere(vec3(sc, qc, -100), aradius);

      //pupils
      theta += thetaRate * dt();
      setColor(vec3(0, 0, 0));
      double pxc = 10 * sin(theta);
      double pyc = height() * 0.38;
      drawSphere(vec3(350 + pxc, pyc, 0), a1radius);

      double s1c = 10 * sin(theta);
      double q1c = height() * 0.38;
      drawSphere(vec3(435 + s1c, q1c, 0), a1radius);

      //body
      setColor(vec3(.87, .48, .06));
      drawSphere(vec3(ac + 43, bc, -200), 140);
      for (int i = 0; i < 50; ++i) {
          drawSphere(vec3(ac + 43, bc - 10, -200), 140);
          bc = bc - 10;
      }

      //nose
      //setColor(vec3(1, 0, 0));
      int startNose3 = (width() * .767);
      int noseRad3 = 25;
      setColor(vec3(.6, .12, .20));
      for (int d = 0; d < 22; ++d) {
          drawSphere(vec3(startNose3, height() * .3, -100), noseRad3);
          startNose3 = startNose3 + 1;
          if (d < 11) {
              noseRad3 += 1;
          }
          if (d == 11) {
              setColor(vec3(.8, .32, .4));
              drawSphere(vec3(startNose3 - 14, height() * .31, 0), 15);
              setColor(vec3(.6, .12, .20));
          }
          if (d > 11) {
              noseRad3 -= 1;
          }
      }

     
  }
     float theta;
    float thetaRate;
    int noseInc;
    vec3 particles[100];
    int size;
    vec3 vel;
    int thetaSun, thetaRateSun;
};

int main(int argc, char** argv) {
  Unique viewer;
  viewer.run();
  return 0;
}

