#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    flowField = FlowField(ofGetWidth()+20, ofGetHeight()+20, 40);
    flowField.initNoise(0.2);
    
 
    for (int i=0; i<3000; i++){
        Particle p;
        p.pos.x = ofRandom(0, ofGetWidth());
        p.pos.y = ofRandom(0, ofGetHeight());
        //p.pos.z = ofRandom(-700,700);
        p.vel.x = ofRandom(-1,1);
        p.vel.y = ofRandom(-1,1);
        //p.vel.z = ofRandom(-1,1);
        particles.push_back(p);
    }
    
    bAnimateField = true;
    bDrawTrails = false;
    bDrawField = false;
    damping = 0.05;
    
    //sphere
    ofPushStyle();
    ofMesh sphere = ofMesh::sphere(1500,100);
    glm::vec3 spherePos = glm::vec3(0,0,0);
    
    for (int i=0; i<sphere.getVertices().size(); i++)
    {
        if (ofRandom(0,50) < 1)
        {
            starfield.addVertex( sphere.getVertices()[i] );
        }
    }
    ofPopStyle();
  
}

//--------------------------------------------------------------
void ofApp::update(){
    
    if (bAnimateField)
    {
        flowField.initNoise(0.1);
    }
    
    for (int i=0; i<particles.size(); i++)
    {
        // get the force at the particle position
        ofVec3f force = flowField.getForceAt(particles[i].pos);
        
        particles[i].applyForce(force);
        particles[i].applyDamping(damping);
        
        particles[i].update();
        
        glm::vec3 pos = particles[i].pos;
       
        if (pos.x < 0){
            pos.x = ofGetWidth();
        }
        else if (pos.x > ofGetWidth()){
            pos.x = 0;
        }
        if (pos.y < 0){
            pos.y = ofGetHeight();
        }
        else if (pos.y > ofGetHeight()){
            pos.y = 0;
        }
        if (pos.z < -800 ){
            pos.z = -800;
        }
        else if (pos.z > 800){
            pos.z = 800;
        }
        particles[i].pos = pos;
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    //tails effects
    if (bDrawTrails){
        ofPushStyle();
        ofSetColor(0,0,0,10);
        ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
        ofPopStyle();
    }
    
    cam.begin();
    ofEnableDepthTest();
   
   
    //star
    ofPushStyle();
    float time = ofGetElapsedTimef();
    ofSetColor(cos(time*3)*255,cos(time*2)*255,0);
    starfield.drawVertices();
    ofPopStyle();
  
    
   
    
    //particle draw
    ofPushMatrix();
    ofTranslate(-ofGetWidth()/2, -ofGetHeight()/2);
    for (int i=0; i<particles.size(); i++)
    {
        particles[i].draw();
    }
    ofPopMatrix();
   


    
    cam.end();
    ofDisableDepthTest();
 
    //instruction
    ofPopStyle();
    ofSetColor(255);
    ofDrawBitmapString("Press t to turn on/off the tail",30,30);
    ofDrawBitmapString("Press space to change it into 3-D space",30,50);
    ofPushStyle();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    //interaction
    if (key == ' ')
    {
      for (int i=0; i<particles.size(); i++)
        {
            particles[i].pos.x = ofRandom(0, ofGetWidth());
            particles[i].pos.y = ofRandom(0, ofGetHeight());
            particles[i].pos.z = ofRandom(-900,900);
            particles[i].vel = ofVec3f();
        }
    }
  
    else if (key == 't' || key == 'T')
    {
        bDrawTrails = !bDrawTrails;
        ofSetBackgroundAuto(!bDrawTrails);
    }
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
