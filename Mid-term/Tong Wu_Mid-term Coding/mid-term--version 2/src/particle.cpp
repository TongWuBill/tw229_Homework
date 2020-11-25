//
//  particle.cpp
//  mid-term
//
//  Created by 侯丁瑞 on 2020/11/22.
//

#include "particle.hpp"

Particle::Particle()
{
    pos = ofVec3f(0);
    vel = ofVec3f(0);
    acc = ofVec3f(0);
}

Particle::Particle(ofVec3f _pos, ofVec3f _vel)
{
    pos = _pos;
    vel = _vel;
    
}

void Particle::applyForce(ofVec3f force)
{
    
    acc += force;
}

void Particle::applyDamping(float strength)
{
    acc -= vel.getNormalized() * strength;
}

void Particle::update()
{
    vel += acc;
    pos += vel;
    acc *= 0;
}

void Particle::draw(){
    
    float velangle = ofRadToDeg(atan2(vel.y*5, vel.x));
    
    float hue = ofMap(velangle, -180,180, 100, 210, true);
    float sat = ofMap(velangle, -180,180, 190, 255, true);
    float brt = ofMap(velangle, -180,180, 200, 225, true);
    
    ofColor color = ofColor::fromHsb(hue,sat,brt);
    ofSetColor(color);
    ofDrawSphere(pos.x,pos.y,pos.z, radius);
    
}
