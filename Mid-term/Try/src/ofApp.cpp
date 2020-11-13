#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
       ofSetBackgroundAuto(false);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    float x = ofMap( ofNoise( ofGetElapsedTimef()/2.0,-10,10), 0, 1, 0, ofGetWidth());
       float y = ofMap( ofNoise( ofGetElapsedTimef()/2.0,10,-10), 0, 1, 0, ofGetHeight());
    float a = ofMap( ofNoise( ofGetElapsedTimef()/2.5,-50), 0, 1, 0, ofGetWidth());
       float b = ofMap( ofNoise( ofGetElapsedTimef()/2.5,50), 0, 1, 0, ofGetHeight());
       ofSetColor(205, 75, 95);
       ofDrawCircle(x,y,3);
    ofSetColor(95, 205, 75);
    ofDrawCircle(a,b,3);
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
