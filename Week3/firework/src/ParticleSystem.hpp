//
//  ParticleSystem.hpp
//  firework
//
//  Created by 吴桐 on 11/14/20.
//

#ifndef ParticleSystem_hpp
#define ParticleSystem_hpp

#include "ofMain.h"
#include "Particle.hpp"

#endif /* ParticleSystem_hpp */

class ParticleSystem {
public:
    
    
    ParticleSystem();
    ParticleSystem(glm::vec2 _pos);
    
    void applyForce(glm::vec2 force);
    
    void update(int numNewParticles = 5, int maxParticles = 500);
    
    void draw();
    
    glm::vec2 pos;                     
    
    vector<Particle> particles;
    
};
