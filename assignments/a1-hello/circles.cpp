#include "atkui/framework.h"
#include <windows.h>

using namespace glm;
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
        theta = 0.0;
        thetaRate = 0.5;
        r = 50.0;
      
    }
    

    virtual void scene() {
        std::vector<vec3> pallet =
        {
           vec3(0,165,227) / 255.0f,
           vec3(141,215,191) / 255.0f,
           vec3(255,150,197) / 255.0f,
           vec3(255,87,104) / 255.0f,
           vec3(255,162,58) / 255.0f
        };
        setColor(vec3(1, 0, 0));
       // drawSphere(vec3(width() * .5, height() * .5, 0), 40);
        
        int N = 15;
        int rotInc = 0;
        int inc = 0;
        int colorInc = 0;
        int thetaInc = 0;
        int theta2 = 0;
        
        for (int k = 0; k < N; ++k) {
            for (int j = 0; j < N; ++j) {
               for (int i = 0; i < 36; ++i) {
                   theta2 = theta + (thetaRate * dt()) * j;
                   theta = theta2; //thetaRate * dt(); //
                    if (j % 2 == 0) {
                        setColor(vec3(pallet[colorInc]));
                        float px = (rotInc * -cos(theta2) + (0.5) * width());
                        float py = (rotInc * sin(theta2) + (0.5) * height());
                        // for (int a = 0; a < 36; ++a) {
                        drawSphere(vec3(px, py, 0), 20);
                        // }
                    }
                    else if (j % 2 != 0) {
                        //setColor(vec3(pallet[colorInc]));
                        float px = (rotInc * cos(theta2) + (0.5) * width());
                        float py = (rotInc * sin(theta2) + (0.5) * height());
                        drawSphere(vec3(px, py, 0), 20);
                    }
                    //Sleep(.5);
                
                    colorInc += 1;
                    if (colorInc >= 5) {
                        colorInc = 0;
                    }

                    

                    

                }
                
                rotInc += 30;
               

            }


        }
          /*  for (int j = 0; j < N; ++j) {
                
                for (int i = 0; i < 36; ++i) {
                    
                    if (j % 2 == 0) {
      
                        setColor(vec3(pallet[colorInc]));
                    
                            float px = (rotInc * -cos(theta + thetaInc) + (0.5) * width());
                            float py = (rotInc * sin(theta + thetaInc) + (0.5) * height());
                            // for (int a = 0; a < 36; ++a) {
                            drawSphere(vec3(px, py, 0), 20);
                            
                        
                        // }
                    }
                    else if (j % 2 != 0) {
                        //setColor(vec3(pallet[colorInc]));
                        float px = (rotInc * cos(theta) + (0.5) * width());
                        float py = (rotInc * sin(theta) + (0.5) * height());
                        drawSphere(vec3(px, py, 0), 20);
                    }
                    //Sleep(.5);
                    
                }
                colorInc += 1;
                if (colorInc >= 6) {
                    colorInc = 0;
                }
                rotInc += 30;
                thetaInc += .50;
                
            }*/
        

        
    }

private:
    float theta;
    float thetaRate;
    float r;
};

int main(int argc, char** argv) {
    Example example;
    example.run();
}
