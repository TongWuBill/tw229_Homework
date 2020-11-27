#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //ofSetBackgroundAuto(false);
    //ofSetBackgroundColor(95);
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofEnableSmoothing();
    ofEnableAlphaBlending();
    snow.load("snow.png");
   
}

//--------------------------------------------------------------
void ofApp::update(){
    change += 15;
  
}
//--------------------------------------------------------------
void ofApp::draw(){
    
    myBrunches.setup(ofRandom(ofGetWidth()),
                      ofGetHeight(),
                      40,
                      80,
                      0.3,
                      PI/3,
                      2,
                      4,
                      0,
                      -PI/2,
                      0,
                      ofColor(130, 50, 20));
    ofSetColor(ofRandom(225,255), ofRandom(215,245), ofRandom(210,250));
    

   

    snow.draw(ofRandom(ofGetWidth()),3*ofRandom(ofGetHeight()/5));
    snow.draw(ofRandom(ofGetWidth()),3*ofRandom(ofGetHeight()/5));
    snow.draw(ofRandom(ofGetWidth()),3*ofRandom(ofGetHeight()/5));
    
    ofSetColor(ofRandom(150,255), ofRandom(140,245), ofRandom(150,250));
    ofDrawBitmapString("Please Double-Click to Make Difference",change,ofGetWidth()/4+50*cos(ofGetElapsedTimef()));
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
    count++;
    if(count%2 == 0){
    ofSetBackgroundAuto(false);
    } else{
        ofSetBackgroundAuto(true);
    }
}
//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
