#include "ofApp.h"

void ofApp::setup(){
    kinect.open();
    img.allocate(521,424, OF_IMAGE_GRAYSCALE);
}

float sum_x = 0;
float sum_y = 0;
float countt = 0;
float avg_x = 0;
float avg_y = 0;
//--------------------------------------------------------------
void ofApp::update(){
    
    kinect.update();
    if(kinect.isFrameNew()){
        texture.loadData(kinect.getRawDepthPixels());
        
        sum_x = 0;
        sum_y = 0;
        countt = 0;
        avg_x = 0;
        avg_y = 0;
        
        for (int y=0; y < texture.getHeight(); y++){
            for (int x=0; x < texture.getWidth(); x++){
                ofColor color = kinect.getDepthPixels().getColor(x, y);
                img.setColor(x, y, color);;
                //ofColor imgcolor = img.getColor(x, y);
                //float brightness = imgcolor.getBrightness();
                float brightness = color.getBrightness();
                if(brightness<20){
                   // ofSetColor(255, 200, 10);
                    if (y < texture.getHeight()-30 and y > 30){
                        if (x < texture.getWidth()-100 and x > 30){
                            sum_x += x;
                            sum_y += y;
                            countt++;
                        }
                    }
                    
                }else{
                    //ofSetColor(10,200,100);
                }
            }
        }
        img.update();
        
        avg_x = sum_x/countt;
        avg_y = sum_y/countt;
        
        //std::cout << texture.getWidth() << " " << texture.getHeight()<< endl;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    img.draw(0,0, 521,424);
    
    ofPushStyle();
    ofSetColor(255, 0, 0);
    ofFill();
    ofTranslate(0, -50);
    ofDrawCircle(avg_x, avg_y, 20);
    ofNoFill();
    ofPopStyle();
}

//--------------------------------------------------------------
void ofApp:: exit(){
    kinect.close();
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
