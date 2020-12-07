#pragma once

#include "ofMain.h"
#include "asteroids.hpp"
#include "ofxKinectV2.h"



class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
    vector<Asteroids> asteroids;
    float rotationdegree = 0;
    
    ofImage space;
    ofImage blackhole;

    glm::vec2 handpoint;
    
    ofxKinectV2 kinect;
    ofTexture texture;
    ofImage img;

    float sum_x = 0;
    float sum_y = 0;
    float countt = 0;
    float avg_x = 0;
    float avg_y = 0;
    
};
