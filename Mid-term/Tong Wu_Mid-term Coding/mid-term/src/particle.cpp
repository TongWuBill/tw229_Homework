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
    
    ofColor petal1 = ofColor::fromHsb(hue/1.1,sat,brt*1.2);
    ofSetColor(petal1);
    ofDrawSphere(pos.x+radius*1.2,pos.y+radius*0.8,pos.z, radius*0.8);
    ofDrawSphere(pos.x+radius*0.85,pos.y+radius*0.8,pos.z+radius*0.6, radius*0.8);
    
    ofColor petal2 = ofColor::fromHsb(hue,sat*1.2,brt*1.2);
    ofSetColor(petal2);
    ofDrawSphere(pos.x,pos.y+radius*0.8,pos.z+radius*1.2, radius*0.8);
    ofDrawSphere(pos.x-radius*0.85,pos.y+radius*0.8,pos.z+radius*0.85, radius*0.8);
    
    ofColor petal3 = ofColor::fromHsb(hue/1.1,sat,brt*1.2);
    ofSetColor(petal3);
    ofDrawSphere(pos.x-radius*1.2,pos.y+radius*0.8,pos.z, radius*0.8);
    ofDrawSphere(pos.x-radius*0.85,pos.y+radius*0.8,pos.z-radius*0.85, radius*0.8);
    
    ofColor petal4 = ofColor::fromHsb(hue,sat*1.2,brt*1.2);
    ofSetColor(petal4);
    ofDrawSphere(pos.x,pos.y+radius*0.8,pos.z-radius*1.2, radius*0.8);
    ofDrawSphere(pos.x+radius*0.85,pos.y+radius*0.8,pos.z-radius*0.85, radius*0.8);
    
    ofColor rachis = ofColor::fromHsb(hue*1.1,sat*1.2,brt*0.85);
    ofSetColor(rachis);
    ofDrawCylinder(pos.x,pos.y-radius*2,pos.z,radius*0.1,radius*2.5);
    
}
