//
//  leaves.cpp
//  seasonal change
//
//  Created by 吴桐 on 11/27/20.
//

#include "leaves.hpp"

//--------------------------------------------------------------
void Leaf::setup(){

    xPos = ofRandom(ofGetWidth());
    yPos = ofGetHeight();
    leafWidth = ofRandom(80,250);
    leafHeight = ofRandom(70,190);
    stemWidth = ofRandom(9, 18);
    stemHeight = ofRandom(30, 80);

    //color
    leafColorLeft = ofColor(ofRandom(166, 186), ofRandom(186, 206), ofRandom(212, 232), ofRandom(200, 255));
    leafColorRight = ofColor(ofRandom(210,230), ofRandom(210,230), ofRandom(210,230), ofRandom(200, 255));
    stemColor = ofColor(135, 50, 20);
   
    flowerColor = ofColor(220, ofRandom(10,30), 60, ofRandom(225, 255));
    
    rotation = ofRandom(135, 225);
    flowerRotate = 0;
    
    scaleFactor = ofRandom(0.8, 1.2);
    
}

//--------------------------------------------------------------
void Leaf::update(){
    
}

//--------------------------------------------------------------
void Leaf::draw(float _xPos, float _yPos, int _segmentsSinceStart){
    
  
    segmentsSinceStart = _segmentsSinceStart;
    
    ofPushMatrix();
    ofPushStyle();  
    
    xPos = _xPos;
    yPos = _yPos;
    
  
    
    ofTranslate(xPos, yPos);
    
    ofRotateDeg(rotation);
    ofScale(scaleFactor, scaleFactor);
    ofSetLineWidth(0);
    
  
//leaf
        ofBeginShape();
        ofSetColor(leafColorLeft);

            
            // Set x Values of Bezier
            float x0 = 0;
            float x1 = x0-leafWidth/2;
            float x2 = x0-leafWidth/4;
            float x3 = x0;

            // Set y Values of Bezier
            float y0 = (2*stemHeight)/3;
            float y1 = y0+leafHeight/3;
            float y2 = y0+(2*leafHeight)/3;
            float y3 = y0+leafHeight;
            
            ofVertex(x0, y0);
            ofBezierVertex(x1, y1, x2, y2, x3, y3);
            ofEndShape();
        
        ofBeginShape();
            ofSetColor(leafColorRight);
            
            // Set x Values of Bezier
            x0 = 0;
            x1 = x0+leafWidth/2;
            x2 = x0+leafWidth/4;
            x3 = x0;
            
            // Set y Values of Bezier
            y0 = (2*stemHeight)/3;
            y1 = y0+leafHeight/3;
            y2 = y0+(2*leafHeight)/3;
            y3 = y0+leafHeight;
            
            ofVertex(x0, y0);
            ofBezierVertex(x1, y1, x2, y2, x3, y3);
            ofEndShape();
        
        ofSetColor(stemColor);
        ofDrawRectangle(0, stemHeight/4, stemWidth/3, stemHeight);
        
        ofDrawTriangle(0-stemWidth/2, 0+stemHeight, 0+stemWidth/2, 0+stemHeight, 0, 0+stemHeight+leafHeight/3);
        

    if (segmentsSinceStart > 1 && segmentsSinceStart < 4) {
       //flower
        ofPushMatrix();
        ofSetColor(flowerColor);
        ofTranslate(0, stemHeight);
        for (int i = 0; i <= 6; i++) {
        ofRotateDeg(flowerRotate);
        ofDrawEllipse(0, 0, 35, 8);
        flowerRotate += 45;
            }
        ofPopMatrix();
    }
    ofPopStyle();
    ofPopMatrix();
}
