#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    for(int i = 0; i <= 10; i++){
        Asteroids tempasteroid;
        asteroids.push_back(tempasteroid);
    }
    space.load("space.jpg");
    blackhole.load("blackhole.png");
}

//--------------------------------------------------------------
void ofApp::update(){
    glm::vec2 mousePos = glm::vec2(ofGetMouseX(), ofGetMouseY());

    for (int i=0; i<10; i++){
    
        glm::vec2 attraction, repulsion;
        
        glm::vec2 dir = mousePos - asteroids[i].pos;
        
        float distance = glm::length(dir);
        
        if (distance > 0) {
            
            glm::vec2 normalizedDir = dir / distance;
            
         if ( distance < 400) {
                
                attraction = normalizedDir;
            }
        }
        
        asteroids[i].applyForce(attraction);
        asteroids[i].applyForce(repulsion);
        asteroids[i].applyDampingForce(0.1);
        asteroids[i].update();
        
        asteroids[i].bounceWindowEdges();
    }
    }


//--------------------------------------------------------------
void ofApp::draw(){
    space.draw(-500,0);
    for(int i = 0; i <= 10; i++){
        asteroids[i].draw();
    }
    
    blackhole.draw(ofGetMouseX()-100,ofGetMouseY()-100);

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
