#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(255);
    ofSetCircleResolution(100);
    money.load("money.png");
}

//--------------------------------------------------------------
void ofApp::update(){
    cc = ofMap(ofGetMouseY(), 0, ofGetHeight(), -50, 10);
    dd = ofMap(ofGetMouseX(), 0, ofGetWidth(), -50, 40);
    eyeball1 = ofVec2f(340, 490);
    eyeball2 = ofVec2f(640, 480);
    
    ofVec2f mouse;
    mouse.x=ofGetMouseX();
    mouse.y=ofGetMouseY();
    
    eyeball1 = eyeball1*0.97 + mouse*0.03;
    eyeball2 = eyeball2*0.97 + mouse*0.03;
}

//--------------------------------------------------------------
void ofApp::draw(){
//hair
    ofSetColor(200+cc,176+dd,173+cc);
    ofDrawTriangle(300, 10, 100, 160, 160, 450);
    ofSetColor(210+dd,176+cc,173+cc);
    ofDrawTriangle(300, 10, 200, 180, 260, 300);
    ofSetColor(205+cc,176+cc,173+dd);
    ofDrawTriangle(300, 10, 260, 300, 300, 150);
    ofSetColor(207+dd,170+cc,173+cc);
    ofDrawTriangle(300, 10, 300, 150, 440, 400);
    ofSetColor(207+cc,176+dd,180+cc);
    ofDrawTriangle(300, 10, 440, 400, 520, 270);
    ofSetColor(207+cc,176+cc,190+dd);
    ofDrawTriangle(500, 3, 300, 10, 520, 270);
    ofSetColor(197+cc,166+dd,200+cc);
    ofDrawTriangle(800, 50, 500, 3, 520, 270);
    ofSetColor(217+dd,176+cc,185+cc);
    ofDrawTriangle(800, 50, 830, 440, 650, 160);
    
    //face
    
    ofSetColor(250+cc,216+cc,213+cc);
    for(int a = 0; a <= 13; a++){
    ofDrawLine(170-a, 390-a, 220-a, 850-a);
    }
    for(int a = 0; a <= 13; a++){
    ofDrawLine(220+a, 850+a, 500+a, 950+a);
    }
    for(int a = 0; a <= 13; a++){
    ofDrawLine(500+a, 950+a, 780+a, 850+a);
    }
    for(int a = 0; a <= 13; a++){
    ofDrawLine(780-a, 850-a, 800-a, 380-a);
    }
    
    //glasses
    ofSetColor(148+cc,110+dd,121+cc);
    ofDrawCircle(340, 490, 120);
    ofSetColor(255);
    ofDrawCircle(340, 490, 110);
    ofSetColor(148+cc,110+cc,121+dd);
    ofDrawCircle(640, 480, 120);
    ofSetColor(255);
    ofDrawCircle(640, 480, 110);
    ofSetColor(148+dd,110+cc,121+cc);
    for(int a = 0; a <= 13; a++){
    ofDrawLine(450+a, 490+a, 520+a, 480+a);
    }
    
    //eyes
    ofSetColor(97+cc,140+cc,172+dd);
    ofDrawEllipse(340, 490, 120, 60);
    ofDrawEllipse(640, 480, 120, 60);
    ofSetColor(67+cc,110+dd,132+cc);
    ofDrawCircle(340, 490, 30);
    ofDrawCircle(640, 480, 30);
    ofSetColor(0);
    ofDrawCircle(eyeball1, 15);
    ofDrawCircle(eyeball2, 15);
    
    //mouse
    ofSetColor(235+dd,167+cc,156+cc);
    for(int a = 0; a <= 12; a++){
    ofDrawLine(380-a, 750-a, 520-a, 820-a);
    }
    for(int a = 0; a <= 12; a++){
    ofDrawLine(520-a, 820-a, 660-a, 750-a);
    }
    
    //money
    ofSetColor(255,255,255);
    money.draw(ofGetMouseX()-50,ofGetMouseY()-50);
    
    
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
