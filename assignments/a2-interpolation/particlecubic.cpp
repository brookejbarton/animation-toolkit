#include "atkui/framework.h"
using namespace glm;

class ParticleCubic : public atkui::Framework {
 public:
  ParticleCubic() : atkui::Framework(atkui::Orthographic) {
  }

  void setup() {
      
  }

  void scene() {
      for (float t = 0; t < 1; t += 0.1) {
          a = Casteljau(t);
          vec3 b = Casteljau(t + 0.1);

          setColor(vec3(1, 1, 0));
          drawLine(a, b);    
      }

      t = fmod(elapsedTime(), 5.0f)/5;

      //level 1
      lerp1 = B0 * (1.0f - t) + B1 * t;
      lerp2 = B1 * (1.0f - t) + B2 * t;
      lerp3 = B2 * (1.0f - t) + B3 * t;
      //level 2
      lerp1_2 = lerp1 * (1.0f - t) + lerp2 * t;
      lerp2_2 = lerp2 * (1.0f - t) + lerp3 * t;
      //level 3
      finalLerp = lerp1_2 * (1.0f - t) + lerp2_2 * t;
      //std::cout << t;

     
      setColor(vec3(1, 0, 0));
      drawSphere(finalLerp, 10);

    setColor(vec3(1));
   // drawSphere(vec3(250, 250, 0), 10);
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
  vec3 animatedCircle() {
      //level 1
      vec3 lerp1 = B0 * (1.0f - dt()) + B1 * dt();
      vec3 lerp2 = B1 * (1.0f - dt()) + B2 * dt();
      vec3 lerp3 = B2 * (1.0f - dt()) + B3 * dt();
      //level 2
      vec3 lerp1_2 = lerp1 * (1.0f - dt()) + lerp2 * dt();
      vec3 lerp2_2 = lerp2 * (1.0f - dt()) + lerp3 * dt();
      //level 3
      vec3 finalLerp = lerp1_2 * (1.0f - dt()) + lerp2_2 * dt();

      return finalLerp;
  }
    private:
      vec3 B0 = vec3(100, 50, 0);
      vec3 B1 = vec3(150, 200, 0);
      vec3 B2 = vec3(250, 100, 0);
      vec3 B3 = vec3(300, 300, 0);
      vec3 lerp1;
      vec3 lerp2;
      vec3 lerp3;
      vec3 lerp1_2;
      vec3 lerp2_2;
      vec3 finalLerp;
      vec3 a;
      float t;
};

int main(int argc, char** argv) {
  ParticleCubic viewer;
  viewer.run();
}

