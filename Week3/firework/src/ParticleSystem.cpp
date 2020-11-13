//
//  ParticleSystem.cpp
//  firework
//
//  Created by 吴桐 on 11/14/20.
//

#include "ParticleSystem.hpp"


ParticleSystem::ParticleSystem()
{
    pos = glm::vec2(0,0);
}

ParticleSystem::ParticleSystem(glm::vec2 _pos)
{
    pos = _pos;
}

void ParticleSystem::applyForce(glm::vec2 force)
{
    
    for (int i=0; i<particles.size(); i++)
    {
        particles[i].applyForce(force);
    }
}

void ParticleSystem::update(int numNewParticles, int maxParticles)
{
  

    for (int i=0; i<numNewParticles; i++)
    {
        glm::vec2 vel   = glm::vec2(ofRandom(-2,2), ofRandom(-1,-5));
        float mass      = ofRandom(.01, 4);
        Particle particle = Particle(pos,vel,mass);
        particles.push_back(particle);
    }

    
    
    for (int i=0; i<particles.size(); i++){
        particles[i].update();
    }


    while (particles.size() > maxParticles){
        particles.erase(particles.begin());    
    }
    
}

void ParticleSystem::draw()
{
    for (int i=0; i<particles.size(); i++)
    {
        particles[i].draw();
    }
}


