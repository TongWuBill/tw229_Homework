#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    webcam.initGrabber(ofGetWidth(), ofGetHeight());
    light.setup();
}

//--------------------------------------------------------------
void ofApp::update(){
    webcam.update();
 
    light.setPosition(0, 0, 0);
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    webcam.draw(0, 0,ofGetWidth(),ofGetHeight());
    //line
    if(m==1){
    for(int i=1; i < ofGetWidth(); i+=16){
        for(int j=1; j< ofGetHeight(); j+=16){
            ofColor color = webcam.getPixels().getColor(i, j);
            float brightness = color.getBrightness();
            ofPushMatrix();
            ofPushStyle();
            ofTranslate(i, j);
            ofRotateZDeg(ofMap(brightness, 0, 255, 0, 360));
            ofSetLineWidth(ofMap(brightness, 0, 255, 5,20));
            ofSetColor(ofRandom(brightness+80), ofRandom(brightness+80), ofRandom(brightness+80));
            ofDrawLine(-8, 0, 8, 0);
            ofPopStyle();
            ofPopMatrix();
        }
    }
        ofDrawBitmapString("Click the mouse to change the mode", 20, 20);
    }
    
    //circle
    if(m==2){
        for(int q=1; q < ofGetWidth(); q+=10){
            for(int w=1; w< ofGetHeight(); w+=10){
                ofColor color = webcam.getPixels().getColor(q,w);
                float saturation = color.getSaturation();
                ofPushMatrix();
                ofPushStyle();
                ofTranslate(q, w);
                radius = ofMap(saturation, 0, 255, 8, 0);
                if(radius>=0 && radius<2){
                    ofSetColor(255, 20, 20);
                }
                if(radius<4 && radius>=2){
                    ofSetColor(25, 200, 20);
                }
                if(radius<6 && radius>=4){
                    ofSetColor(25, 20, 200);
                }
                if(radius>=6){
                    ofSetColor(215, 220, 200);
                }
                ofDrawCircle(0, 0, radius);
                ofPopMatrix();
                ofPopStyle();
            }
        }
        ofDrawBitmapString("Click the mouse to change the mode", 20, 20);
    }
    
    //3d box
    if(m==3){
        for(int e=1; e < ofGetWidth(); e+=40){
            for(int r=1; r< ofGetHeight(); r+=40){
                ofColor color = webcam.getPixels().getColor(e, r);
                float brightness = color.getBrightness();
                ofEnableDepthTest();
                light.enable();
                ofPushMatrix();
                ofPushStyle();
                ofTranslate(e, r);
                ofSetBoxResolution(6);
                ofRotateDeg(ofMap(brightness, 0, 255, 0,360), 10, 20, 30);
                ofDrawBox(0, 0, 0, ofMap(brightness, 0, 255, 4,30), ofMap(brightness, 0, 255, 4,30), ofMap(brightness, 0, 255, 4,30));
                ofPopMatrix();
                ofPopStyle();
                light.disable();
                ofDisableDepthTest();
            }
        }
        ofDrawBitmapString("Click the mouse to change the mode", 20, 20);
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
    m++;
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
