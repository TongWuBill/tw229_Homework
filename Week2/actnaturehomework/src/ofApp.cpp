#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    flower.load("flower.png");
    garden.load("garden.jpg");
    gui.setup();
    gui.add(windvolume.setup("wind volume",1,1,2));
}

//--------------------------------------------------------------
void ofApp::update(){
    theta += PI/90;
}

//--------------------------------------------------------------
void ofApp::draw(){
    garden.draw(0,0);
    for(int i =0; i <=200; i++){
        a = ofMap(i, 0, 150, 5, 20);
        b = ofMap(i, 0, 150, 0, 100);
        c = windvolume;
        ofSetColor(50-b/4, 155+b, 50-b/4);
        ofDrawLine(390-c*a*cos(theta), 800-i, 410-c*a*cos(theta), 800-i);
        ofDrawLine(190-c*a*sin(theta), 800-i, 210-c*a*sin(theta), 800-i);
        ofDrawLine(590-c*a*sin(theta), 800-i, 610-c*a*sin(theta), 800-i);
        ofSetColor(50, 155, 50);
        ofDrawEllipse(380-c*18*cos(theta), 680, 40, 20);
        ofDrawEllipse(420-c*18*cos(theta), 710, 40, 20);
        ofDrawEllipse(180-c*18*sin(theta), 680, 40, 20);
        ofDrawEllipse(220-c*18*sin(theta), 710, 40, 20);
        ofDrawEllipse(580-c*18*sin(theta), 680, 40, 20);
        ofDrawEllipse(620-c*18*sin(theta), 710, 40, 20);
        ofSetColor(255, 255, 255);
        flower.draw(340-c*20*cos(theta),540);
        flower.draw(140-c*20*sin(theta),540);
        flower.draw(540-c*20*sin(theta),540);
    }
    gui.draw();
    
    ofDrawBitmapString("Change the Wind Volume to Change the Flower Swing Speed",10,70);
    
   
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
