//
//  asteroids.cpp
//  interstellar
//
//  Created by 吴桐 on 11/13/20.
//

#include "asteroids.hpp"

Asteroids::Asteroids()
{
    pos = glm::vec2(ofRandom(1000),ofRandom(700));
    mass = ofRandom(8,15);
    
    vel = glm::vec2(0,0);
    acc = glm::vec2(0,0);
}

Asteroids::Asteroids(glm::vec2 _pos, float _mass){
    pos     = _pos;
    mass    = _mass;
    
    vel     = glm::vec2(0,0);
    acc     = glm::vec2(0,0);
}

void Asteroids::applyForce(glm::vec2 force){
    acc += force/mass;
}

void Asteroids::applyDampingForce(float strength)
{
    float length = glm::length(vel);
    if (length != 0.0){
        glm::vec2 direction = vel / length;
        applyForce( -direction * strength );
    }
}

void Asteroids::bounceWindowEdges() {
    
    if (pos.x < 0) {
        pos.x = 0;
        vel.x *= -1;
    }
    
    if (pos.x > ofGetWidth()) {
        pos.x = ofGetWidth();
        vel.x *= -1;
    }
    
    if (pos.y < 0) {
        pos.y = 0;
        vel.y *= -1;
    }
    
    if (pos.y > ofGetHeight()) {
        pos.y = ofGetHeight();
        vel.y *= -1;
    }
}

void Asteroids::update()
{
    vel += acc;
    pos += vel;
    
    acc *= 0;
}

void Asteroids::draw()
{
    
    ofPushStyle();
    
    float aa = ofRandom(100,160);
    float ab = ofRandom(100,160);
    float ac = ofRandom(100,160);
    ofSetColor(aa, ab, ac);
    
    ofDrawCircle(pos, mass * 2.0);
    
    ofPopStyle();
    
}

