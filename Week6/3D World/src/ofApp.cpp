#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    cam.setPosition(ofPoint(-ofGetWidth()/4, -ofGetHeight()/4, 2500));
    flowField = FlowField(ofGetWidth()+20, ofGetHeight()+20, 40);
    flowField.initNoise(0.2);
    
 
    for (int i=0; i<15000; i++){
        Particle p;
        p.pos.x = ofRandom(0, ofGetWidth()-100);
        p.pos.y = ofRandom(0, ofGetHeight()-100);
        p.pos.z = ofRandom(-200,200);
        p.vel.x = ofRandom(-8,8);
        p.vel.y = ofRandom(-8,8);
        p.vel.z = ofRandom(-8,8);
        particles.push_back(p);
    }
    
    bAnimateField = true;
    bDrawTrails = false;
    bDrawField = false;
    damping = 0.08;
    
    //sphere
    ofPushStyle();
    ofMesh sphere = ofMesh::sphere(800,100);
    glm::vec3 spherePos = glm::vec3(0,0,0);
    
    for (int i=0; i<sphere.getVertices().size(); i++)
    {
        if (ofRandom(0,5) < 1)
        {
            starfield.addVertex( sphere.getVertices()[i] );
        }
    }
    ofPopStyle();
  
    light.setup();
    
    gui.setup();
    gui.add(lightpositionx.setup("lightpositionx",0,-800,800));
    gui.add(lightpositiony.setup("lightpositiony",500,-800,800));
    gui.add(lightpositionz.setup("lightpositionz",0,-800,800));
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
    
    light.setPosition(lightpositionx,lightpositiony,lightpositionz);

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundGradient(ofColor::powderBlue, ofColor::mediumPurple,OF_GRADIENT_LINEAR);
    //tails effects
    if (bDrawTrails){
        ofPushStyle();
        ofSetColor(0,0,0,10);
        ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
        ofPopStyle();
    }
    
    ofEnableDepthTest();
    light.enable();
    cam.begin();
   
    //star
    ofPushStyle();
    float time = ofGetElapsedTimef();
    ofSetColor(cos(time*3)*255);
    starfield.drawVertices();
    ofPopStyle();
  
    
    if (bDrawField)
    {
        // draw forces x100 magnitude to see them
        flowField.draw(100.);
    }
    
    //particle draw
    ofPushMatrix();
    ofTranslate(-ofGetWidth()/2, -ofGetHeight()/2);
    for (int i=0; i<particles.size(); i++)
    {
        particles[i].draw();
    }
    ofPopMatrix();
   
    ofPushStyle();
    ofSetColor(255, 255, 100);
    ofDrawSphere(lightpositionx,lightpositiony,lightpositionz,100);
    ofPopStyle();

    
    cam.end();
    ofDisableDepthTest();
    light.disable();
  
    //gui draw
    gui.draw();
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
            particles[i].pos.z = ofRandom(-400,400);
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
