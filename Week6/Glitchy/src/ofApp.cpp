#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){\
    //gui
    gui.setup();
    gui.add(glitchy.setup("glitchy",1,1,5));
    
    //video
    cyberpunk.load("cyberpunk.mp4");
    newvideo.allocate(cyberpunk.getWidth(), cyberpunk.getHeight(), OF_IMAGE_COLOR);
    cyberpunk.play();
}

//--------------------------------------------------------------
void ofApp::update(){
   
    float time = ofGetElapsedTimef();
    
    cyberpunk.update();
    
    if (cyberpunk.isFrameNew()){
        float time = ofGetElapsedTimef()*2;
        glm::vec2 mouse = glm::vec2(ofGetMouseX(), ofGetMouseY());
        glm::vec2 mouseNorm = mouse / ofGetWindowSize();
        glm::vec2 cyberpunkSize = glm::vec2(cyberpunk.getWidth(), cyberpunk.getHeight());
        
        for(int x=0; x < cyberpunk.getWidth(); x++){
            for(int y = 0; y < cyberpunk.getHeight();y++){
                
                glm::vec2 pos = glm::vec2(x,y) / cyberpunkSize;
                ofColor color = cyberpunk.getPixels().getColor(x, y);
                
                float saturation = color.getSaturation();
                float brightness = color.getBrightness();
                
                glm::vec2 change;
                
                change.x = ofNoise(time) * mouseNorm.x/2 * ((brightness+saturation)/2) * glitchy;
                change.y = ofNoise(time) * mouseNorm.y/2 * ((brightness+saturation)/2) * glitchy;
                
                int changeX = int(x + 2*change.x) % int(cyberpunk.getWidth());
                int changeY = int(y + 2*change.y) % int(cyberpunk.getHeight());
               
                newvideo.setColor(changeX, changeY, color);
            }
        }
        newvideo.update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
  
    newvideo.draw(0,0, ofGetWidth(), ofGetHeight());
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
