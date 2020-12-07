#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	//ofBackground(255);
    
	ofSetVerticalSync(true);
	
	// billboard particles
	for (int i=0; i<NUM_BILLBOARDS; i++) {
		pos[i].x = ofRandomWidth();
		pos[i].y = ofRandomHeight();
		vel[i].x = ofRandomf();
		vel[i].y = ofRandomf();
		home[i] = pos[i];
		pointSizes[i] = ofRandom(200, 300);
		rotations[i] = ofRandom(0, 360);
	}
    
    for (int j=0; j<NUM_BILLBOARDS2; j++) {
        pos2[j].x = ofRandomWidth();
        pos2[j].y = ofRandomHeight();
        vel2[j].x = ofRandomf();
        vel2[j].y = ofRandomf();
        home2[j] = pos2[j];
        pointSizes2[j] = ofRandom(100, 200);
        rotations[j] = ofRandom(0, 360);
    }
	
	// set the vertex data
	vbo.setVertexData(pos, NUM_BILLBOARDS, GL_DYNAMIC_DRAW);
    vbo2.setVertexData(pos2, NUM_BILLBOARDS2, GL_DYNAMIC_DRAW);
    vbo3.setVertexData(pos, NUM_BILLBOARDS, GL_DYNAMIC_DRAW);
    
    if(ofIsGLProgrammableRenderer()){
		shader.load("shaderGL3/Billboard");
	}else{
		shader.load("shaderGL2/Billboard");
	}
    
    if(ofIsGLProgrammableRenderer()){
        shader2.load("shaderGL4/Billboard");
    }else{
        shader2.load("shaderGL2/Billboard");
    }
	
	ofDisableArbTex();
  
    
	texture.load("snow.png");
    juhua.load("juhua.png");
    lanhua.load("lanhua.png");

	// we are getting the location of the point size attribute
	// we then set the pointSizes to the vertex attritbute
	// we then bind and then enable
	shader.begin();
	
    int pointAttLoc = shader.getAttributeLocation("pointSize");
	vbo.setAttributeData(pointAttLoc, pointSizes, 1, NUM_BILLBOARDS, GL_DYNAMIC_DRAW);

	// rotate the snow based on the velocity
	int angleLoc = shader.getAttributeLocation("angle");
	vbo.setAttributeData(angleLoc, rotations, 1, NUM_BILLBOARDS, GL_DYNAMIC_DRAW);
    
 
    int pointAttLoc3 = shader.getAttributeLocation("pointSize3");
    vbo3.setAttributeData(pointAttLoc3, pointSizes3, 1, NUM_BILLBOARDS, GL_DYNAMIC_DRAW);

    // rotate the snow based on the velocity
    int angleLoc3 = shader.getAttributeLocation("angle3");
    vbo3.setAttributeData(angleLoc3, rotations, 1, NUM_BILLBOARDS, GL_DYNAMIC_DRAW);
	shader.end();
    
    shader2.begin();
    int pointAttLoc2 = shader.getAttributeLocation("pointSize2");
    vbo2.setAttributeData(pointAttLoc2, pointSizes2, 0, NUM_BILLBOARDS2, GL_DYNAMIC_DRAW);

    // rotate the snow based on the velocity
    int angleLoc2 = shader.getAttributeLocation("angle2");
    vbo2.setAttributeData(angleLoc2, rotations, 0, NUM_BILLBOARDS2, GL_DYNAMIC_DRAW);
    shader2.end();
     
    kinect.open();
    img.allocate(521,424, OF_IMAGE_GRAYSCALE);
}

//--------------------------------------------------------------
void ofApp::update() {
    /*
	glm::vec2 mouse(ofGetMouseX(), ofGetMouseY());
	glm::vec2 mouseVec(ofGetPreviousMouseX()-ofGetMouseX(), ofGetPreviousMouseY()-ofGetMouseY());
	glm::clamp(mouseVec, 0.0f, 10.0f);
     */
    
    kinect.update();
    if(kinect.isFrameNew()){
        gpuimage.loadData(kinect.getRawDepthPixels());
        
        sum_x = 0;
        sum_y = 0;
        countt = 0;
        avg_x = 0;
        avg_y = 0;
        
        for (int y=0; y < gpuimage.getHeight(); y++){
            for (int x=0; x < gpuimage.getWidth(); x++){
                ofColor color = kinect.getDepthPixels().getColor(x, y);
                img.setColor(x, y, color);;
                //ofColor imgcolor = img.getColor(x, y);
                //float brightness = imgcolor.getBrightness();
                float brightness = color.getBrightness();
                if(brightness<20){
                   // ofSetColor(255, 200, 10);
                    if (y < gpuimage.getHeight()-30 and y > 30){
                        if (x < gpuimage.getWidth()-100 and x > 30){
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
        
        avg_x = (sum_x/countt)*8;
        avg_y = (sum_y/countt)*5;
        
        //std::cout << texture.getWidth() << " " << texture.getHeight()<< endl;
    }
    
    
    glm::vec2 handpoint = glm::vec2(avg_x,avg_y);
    glm::vec2 mouseVec(ofGetMouseX()-handpoint.x,ofGetMouseY()-handpoint.y);
    glm::clamp(mouseVec, 0.0f, 10.0f);
     

	//1
	for (int i=0; i<NUM_BILLBOARDS; i++) {
		ofSeedRandom(i);
		if(glm::distance(handpoint,pos[i]) < ofRandom(100, 400)) {
			vel[i] -= mouseVec;
		}
		
		pos[i] += vel[i];
		vel[i] *= 0.84f;
		
		if(pos[i].x < 0) pos[i].x = ofGetWidth();
		if(pos[i].x > ofGetWidth()) pos[i].x = 0;
		if(pos[i].y < 0) pos[i].y = ofGetHeight();
		if(pos[i].y > ofGetHeight()) pos[i].y = 0;
		
		glm::vec2 center(ofGetWidth()/2, ofGetHeight()/2);
		glm::vec2 frc = home[i] - pos[i];
		if(glm::length(frc) > 20.0) {
			frc = glm::normalize(frc);
			frc *= 0.84;
			vel[i] += frc;
		}
		
		// get the 2d heading
		float angle = (float)atan2(-vel[i].y, vel[i].x) + PI;
		rotations[i] = (angle * -1.0);
	}
    
    //2
    for (int j=0; j<NUM_BILLBOARDS2; j++) {
        ofSeedRandom(j);
        if(glm::distance(handpoint,pos2[j]) < ofRandom(100, 400)) {
            vel2[j] -= mouseVec;
        }
        
        pos2[j] += vel2[j];
        vel2[j] *= 0.7f;
        
        if(pos2[j].x < 0) pos2[j].x = ofGetWidth();
        if(pos2[j].x > ofGetWidth()) pos2[j].x = 0;
        if(pos2[j].y < 0) pos2[j].y = ofGetHeight();
        if(pos2[j].y > ofGetHeight()) pos2[j].y = 0;
        
        glm::vec2 center(ofGetWidth()/2-100, ofGetHeight()/2+100);
        glm::vec2 frc = home2[j] - pos2[j];
        if(glm::length(frc) > 20.0) {
            frc = glm::normalize(frc);
            frc *= 0.7;
            vel2[j] += frc;
        }
        
        // get the 2d heading
        float angle = (float)atan2(-vel2[j].y, vel2[j].x) + PI/2;
        rotations[j] = (angle * -1.0);
    }
    
}

//--------------------------------------------------------------
void ofApp::draw() {
    
    //ofBackgroundGradient(ofColor::fromHsb(hue1, 255, 255), ofColor::fromHsb(hue2, 255, 255),OF_GRADIENT_BAR );
    ofBackgroundGradient(ofColor::powderBlue, ofColor::mediumPurple,OF_GRADIENT_LINEAR );
   
    //ofBackground(0);
	ofEnableAlphaBlending();
	ofSetColor(255);
	
	shader.begin();
    shader2.begin();
	ofEnablePointSprites();
	


    //lanhua2
    lanhua.getTexture().bind();
    vbo2.updateVertexData(pos, NUM_BILLBOARDS2);

    // rotate the snow based on the velocity
    int angleLoc2 = shader.getAttributeLocation("angle2");
    vbo2.updateAttributeData(angleLoc2, rotations, NUM_BILLBOARDS2);

    vbo2.draw(GL_POINTS, 0, NUM_BILLBOARDS2);
    lanhua.getTexture().unbind();
    
    
    //juhua3
    juhua.getTexture().bind();
    
    vbo3.updateVertexData(pos, NUM_BILLBOARDS);

    // rotate the snow based on the velocity
    int angleLoc3 = shader.getAttributeLocation("angle3");
    vbo3.updateAttributeData(angleLoc3, rotations, NUM_BILLBOARDS);

    vbo3.draw(GL_POINTS, 0, NUM_BILLBOARDS);
    juhua.getTexture().unbind();
    
    //texture1
    
    texture.getTexture().bind();
  
    vbo.updateVertexData(pos, NUM_BILLBOARDS);

    // rotate the snow based on the velocity
    int angleLoc = shader.getAttributeLocation("angle");
    vbo.updateAttributeData(angleLoc, rotations, NUM_BILLBOARDS);

    vbo.draw(GL_POINTS, 0, NUM_BILLBOARDS);
    
    texture.getTexture().unbind();
     

	ofDisablePointSprites();
	shader.end();
    shader2.end();
    
    ofPushStyle();
    ofPushMatrix();
    ofSetColor(255, 0, 0);
    ofFill();
    ofTranslate(0, -50);
    ofDrawCircle(avg_x, avg_y, 10);
    ofNoFill();
    ofPopMatrix();
    ofPopStyle();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if(key == 'f') {
		ofToggleFullscreen();
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
	
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
	
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
	for (int i=0; i<NUM_BILLBOARDS; i++) {
		home[i].x = ofRandomWidth();
		home[i].y = ofRandomHeight();
	}
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
