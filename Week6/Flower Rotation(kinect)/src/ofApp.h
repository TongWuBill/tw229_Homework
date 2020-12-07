#pragma once
#include "ofMain.h"
#include "ofVbo.h"
#include "ofxKinectV2.h"

#define NUM_BILLBOARDS  2000
#define NUM_BILLBOARDS2 500
#define NUM_BILLBOARDS3 200

class ofApp : public ofBaseApp {
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
		
		ofVbo vbo;
    ofVbo vbo2;
    ofVbo vbo3;
		ofShader shader;
    ofShader shader2;
		ofImage texture;
    ofImage juhua;
    ofImage lanhua;
    
    
    glm::vec2 handpoint;
    
    ofxKinectV2 kinect;
    ofTexture gpuimage;
    ofImage img;

    float sum_x = 0;
    float sum_y = 0;
    float countt = 0;
    float avg_x = 0;
    float avg_y = 0;
    
    
		glm::vec2 pos[NUM_BILLBOARDS];
		glm::vec2 vel[NUM_BILLBOARDS];
		glm::vec2 home[NUM_BILLBOARDS];
		float pointSizes[NUM_BILLBOARDS];
		float rotations[NUM_BILLBOARDS];
    
    glm::vec2 pos2[NUM_BILLBOARDS2];
    glm::vec2 vel2[NUM_BILLBOARDS2];
    glm::vec2 home2[NUM_BILLBOARDS2];
    float pointSizes2[NUM_BILLBOARDS2];
    float rotations2[NUM_BILLBOARDS2];
    
    glm::vec2 pos3[NUM_BILLBOARDS3];
    glm::vec2 vel3[NUM_BILLBOARDS3];
    glm::vec2 home3[NUM_BILLBOARDS3];
    float pointSizes3[NUM_BILLBOARDS3];
    float rotations3[NUM_BILLBOARDS3];
    
};









