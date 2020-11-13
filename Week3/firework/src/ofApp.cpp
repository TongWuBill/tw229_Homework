#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    sky.load("sky.jpg");
    glm::vec2 pos = glm::vec2(ofGetWidth() * 0.5, ofGetHeight() * 0.5);
    ParticleSystem particleSystem = ParticleSystem(pos);
    
    particleSystems.push_back(particleSystem);
  
    gravity = glm::vec2(0, .25);
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i=0; i<particleSystems.size(); i++){
        particleSystems[i].applyForce(gravity);
        particleSystems[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    sky.draw(-500,0);
    for (int i=0; i<particleSystems.size(); i++){
        particleSystems[i].draw();
    }
}


//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    particleSystems.push_back( ParticleSystem(glm::vec2(x,y)) );
}

