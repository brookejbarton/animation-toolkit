#include <iostream>
#include "atkui/framework.h"
using namespace glm;

class ScreenSaver : public atkui::Framework
{
public:
    ScreenSaver() : atkui::Framework(atkui::Orthographic, 400, 400) {
    }
    struct curve1 {
        vec4 vecSet;
    };
    struct curve2 {
        vec4 vecSet;
    };
    struct current {
        vec4 vecSet;
    };
    virtual void setup() {
        
    }

    virtual void scene()
    {   
        struct curve1 curve1;
        curve1.vecSet = newVec();

        struct curve2 curve2;
        curve2.vecSet = newVec();

        struct current current;
        current.vecSet = vec4(curve1.vecSet.x, curve1.vecSet.y, curve2.vecSet.z, curve2.vecSet.a);

        for (float t = 0; t <= 1.1f; t += 0.1f) {
            curve1_1 = Casteljau(t, curve1.vecSet);
            curve1_2 = Casteljau(t+0.1, curve1.vecSet);

            curve2_1 = Casteljau(t, curve2.vecSet);
            curve2_2 = Casteljau(t + 0.1, curve2.vecSet);

            vec3 current1 = Casteljau(t, current.vecSet);
            vec3 current2 = Casteljau(t+0.1, current.vecSet);

            setColor(vec3(1,0,0));
            drawLine(curve1_1, curve1_2);
            setColor(vec3(agl::random(0.1f, 0.9f), agl::random(0.1f, 0.9f), agl::random(0.1f, 0.9f)));
            drawLine(curve2_1, curve2_2);
            drawLine(current1, current2);

        }


    }
    vec4 newVec() {
        B0 = vec3(agl::random(100.0f, 400.0f), agl::random(100.0f, 400.0f), 0);
        B1 = vec3(agl::random(100.0f, 400.0f), agl::random(100.0f, 400.0f), 0);
        B2 = vec3(agl::random(100.0f, 400.0f), agl::random(100.0f, 400.0f), 0);
        B3 = vec3(agl::random(100.0f, 400.0f), agl::random(100.0f, 400.0f), 0);
        vec4 vecSet = vec4(B0, B1, B2, B3);
        return vecSet;
    }

    vec3 Casteljau(float t, vec4 vecSet) {
        B0 = vec3(vecSet.x);
        B1 = vec3(vecSet.y);
        B2 = vec3(vecSet.z);
        B3 = vec3(vecSet.a);

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

private:
    vec3 B0;
    vec3 B1;
    vec3 B2;
    vec3 B3;
    vec3 curve1_1;
    vec3 curve1_2;
    vec3 curve2_1;
    vec3 curve2_2;
};

int main(int argc, char** argv) {
    ScreenSaver viewer;
    viewer.run();
}
