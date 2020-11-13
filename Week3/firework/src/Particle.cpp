//
//  Particle.cpp
//  firework
//
//  Created by 吴桐 on 11/14/20.
//

#include "Particle.hpp"

Particle::Particle()
{

    pos = glm::vec2(0,0);
    vel = glm::vec2(0,0);
    acc = glm::vec2(0,0);
    playTime = ofGetElapsedTimef();
}

Particle::Particle(glm::vec2 _pos, glm::vec2 _vel, float _mass)
{
    
    pos = _pos;
    vel = _vel;
    mass = _mass;
    
    playTime = ofGetElapsedTimef();
}

void Particle::applyForce(glm::vec2 force)
{
    acc += force / mass;
}

void Particle::update()
{
    vel += acc;
    pos += vel;
    acc *= 0;
    
}

void Particle::draw()
{
    ofPushStyle();
    

    float hue = ofRandom(0,255);
    float aliveTime = ofGetElapsedTimef() - playTime;
    
    float alpha = ofMap(aliveTime, 0, 2, 255, 0, true);
    

    ofColor color = ofColor::fromHsb(hue,155,255,alpha);
    ofSetColor(color);
    

    ofDrawCircle(pos, mass * 1.5);
    

    
    ofPopStyle();
}

