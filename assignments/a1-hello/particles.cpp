#include "atkui/framework.cpp"

using glm::vec3;

class Example : public atkui::Framework {
public:
    Example() : atkui::Framework(atkui::Orthographic) {
    }

    struct PARTICLE {
        vec3 currentPos;
        vec3 vel;
        vec3 color;
    };

    virtual void setup() {
        for (int i = 0; i < 100; ++i) {
            struct PARTICLE particle; 
            particle.currentPos = vec3(agl::randomUnitVector());
            particle.vel = vec3(agl::randomUnitVector()); //15.0f * vec3(1, 3, 4); //
            particle.color = vec3(0.2+agl::random(-0.2f, 0.2f), 0.8 + agl::random(-0.2f, 0.2f), 0.2 + agl::random(-0.2f, 0.2f));
            particleArray[i] = (particle.currentPos, particle.vel, particle.color);
        }
    };

    virtual void scene() {
        for (int i = 0; i < 100; ++i) {
            particleArray[i].x = particleArray[i].x + particleArray[i].y * elapsedTime();
            if (particleArray[i].x > width()) {
                particleArray[i].x = (0, 0, 0);
            }
            setColor(vec3(particleArray[i].z));
            drawSphere(particleArray[i], 25);
        }
    }
    private:
        vec3 particleArray[100];  
};

int main(int argc, char** argv) {
    Example example;
    example.run();
}
