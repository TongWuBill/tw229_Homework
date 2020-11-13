#pragma once

#include "ofMain.h"
#include "ParticleSystem.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
	
		void mousePressed(int x, int y, int button);
		
		
    ofImage sky;
    
    vector<ParticleSystem> particleSystems;
    glm::vec2 gravity;
};
