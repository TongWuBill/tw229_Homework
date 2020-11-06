#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetCircleResolution(100);
    gui.setup();
    gui.add(windvolume.setup("wind volume",100,0,500));
    smile.load("smile.png");
    sad.load("sad.png");
    cry.load("cry.png");
    sunshine.load("sunshine.jpg");
    rainy.load("rainy.jpg");
    storm.load("storm.jpg");
}

//--------------------------------------------------------------
void ofApp::update(){
    ofVec2f mouse;
    mouse.x = ofGetMouseX();
    mouse.y = ofGetMouseY();
    
    float pct = windvolume/50000;
    ball.x = ball.x * (1.-pct) + mouse.x * pct;
   
    theta += PI/45;
    ball.y = ofGetHeight()/2 + (windvolume/5)*cos(theta);
}

//--------------------------------------------------------------
void ofApp::draw(){
  
    
    if(windvolume>=0 && windvolume < 150){
    sunshine.draw(-300,0);
    smile.draw(ball);
        
    }
    if(windvolume>=150 && windvolume < 350){
    rainy.draw(-350,0);
    sad.draw(ball);
    }
    if(windvolume>=350 && windvolume <= 500){
    storm.draw(0,0);
    cry.draw(ball);
    }
       
    ofDrawBitmapString("Please Change the Wind Volume to Get Different Effects",10,70);
    ofDrawBitmapString("The Direction of Wind Follows the Mouse",10,85);
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
