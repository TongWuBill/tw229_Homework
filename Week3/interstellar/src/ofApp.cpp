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
    
    kinect.open();
    img.allocate(521,424, OF_IMAGE_GRAYSCALE);
}

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
    
    glm::vec2 handpoint = glm::vec2(avg_x,avg_y);

    for (int i=0; i<10; i++){
    
        glm::vec2 attraction, repulsion;
        
        glm::vec2 dir = handpoint - asteroids[i].pos;
        
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
    
    blackhole.draw(handpoint.x-100,handpoint.y-100);
    
    
    ofPushStyle();
    ofPushMatrix();
    ofSetColor(255, 0, 0);
    ofFill();
    ofTranslate(0, -50);
    ofScale(2,2,2);
    ofDrawCircle(avg_x, avg_y, 20);
    ofNoFill();
    ofPopMatrix();
    ofPopStyle();

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
