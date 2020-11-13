//
//  Particle.hpp
//  firework
//
//  Created by 吴桐 on 11/14/20.
//

#ifndef Particle_hpp
#define Particle_hpp

#include "ofMain.h"

#endif /* Particle_hpp */

class Particle {
    
public:
    
    Particle();
    Particle(glm::vec2 _pos, glm::vec2 _vel, float _mass);
    
    void applyForce(glm::vec2 force);
    void update();
    void draw();

    
    glm::vec2 pos, vel, acc;
    float mass;
    float hue;
    float playTime;
    
};
