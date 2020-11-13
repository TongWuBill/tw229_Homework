#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    
    left.load("left.png");
    
    right.load("right.png");
    
    love.load("love.jpg");
    
    pos1  = glm::vec2(ofGetWidth()/2-100,300);
    pos2  = glm::vec2(ofGetWidth()/2+100,300);
    
    vel     = glm::vec2(1,0);
    acc     = glm::vec2(0,0);
}

//--------------------------------------------------------------
void ofApp::update(){
    vel += acc;
    pos1 -= vel;
    pos2 += vel;
    
    glm::vec2 dir = pos1-pos2;
    float distance = glm::length(dir);
    
    ofSetColor(40, 40, 40);
    
    if(distance < 78){
    ofSetColor(255, 40, 40);

        vel     = glm::vec2(0,0);
        acc     = glm::vec2(0,0);
    
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofPushStyle();
    ofSetColor(255, 255, 255);
    love.draw(-100,0);
    ofPopStyle();

    left.draw(pos1);
    right.draw(pos2);
    
    if(vel != glm::vec2(0,0)){
        ofDrawBitmapString("Constantly clikc to get lover back",ofGetWidth()/2,ofGetHeight()/2-150);
    }else{
        ofDrawBitmapString("Love is Love!!!",ofGetWidth()/2,ofGetHeight()/2-150);
    }
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
    acc += glm::vec2(-0.001,0);;
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
