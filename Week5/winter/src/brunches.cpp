//
//  brunches.cpp
//  seasonal change
//
//  Created by 吴桐 on 11/27/20.
//

#include "brunches.hpp"

//--------------------------------------------------------------
void Brunches::setup(
                  float _xPos,
                  float _yPos,
                  float _width,
                  float _length,
                  float _splitPercentage,
                  float _maxSplitAngle,
                  float _maxSubdivisions,
                  float _maxSegments,
                  float _segmentsSinceStart,
                  float _angle,
                  float _curvature,
                  ofColor _color)
{
    ofSetFrameRate(2);
    
    ofPushMatrix();
    
    
//set the pointer
    xPos = _xPos;
    yPos = _yPos;
    width = _width;
    length = _length;
    splitPercentage = _splitPercentage;
    maxSplitAngle = _maxSplitAngle;
    maxSubdivisions = _maxSubdivisions;
    maxSegments = _maxSegments;
    segmentsSinceStart = _segmentsSinceStart;
    angle = _angle;
    curvature = _curvature;
    color = _color;
   
    
    
    numLeaves = (int)ofRandom(1,2);


    if (segmentsSinceStart == maxSegments) {
        numLeaves = (int)ofRandom(1,2);
    }
    if (segmentsSinceStart == 0) {
        numLeaves = 0;
    }
    
    for (int i = 0; i < numLeaves; i++) {
        Leaf tempLeaf;
        tempLeaf.setup();
        myLeaves.push_back(tempLeaf);
    }
    
    
 
    ofSetColor(color);
    ofSetLineWidth((int)width);
    ofDrawLine(xPos, yPos, xPos+length*cos(angle)/3, yPos+length*sin(angle));
  
    for (int i = 0; i < numLeaves; i++) {
        myLeaves[i].draw(xPos+length*cos(angle), yPos+length*sin(angle),  segmentsSinceStart);
    }

    

    xPos += length*cos(angle);
    yPos += length*sin(angle);
    width = width*ofRandom(0.8,1.2);
    length = length*ofRandom(0.5, 0.8);
    segmentsSinceStart += 1;
    angle += curvature;
    curvature += ofRandom(0, (float)(2*PI)/360.0);
    
    if (segmentsSinceStart <= maxSegments){
        
        Brunches subBranch;
        subBranch.setup(xPos, yPos, width, length, splitPercentage, maxSplitAngle, maxSubdivisions, maxSegments, segmentsSinceStart, angle, curvature, color);
        
        if (ofRandom(0, 1) > splitPercentage){
            
            subBranch.setup(xPos, yPos, width, length, splitPercentage, maxSplitAngle, maxSubdivisions, maxSegments, segmentsSinceStart, angle, curvature, color);
        }
        
        
        else{
            Brunches subBranch_1;
            float angle_1 = angle-ofRandom(0, maxSplitAngle);
            
          
            Brunches subBranch_2;
            float angle_2 = angle+ofRandom(0, maxSplitAngle);
            
            subBranch_1.setup(xPos, yPos, width, length, splitPercentage, maxSplitAngle, maxSubdivisions, maxSegments, segmentsSinceStart, angle_1, curvature, color);
            subBranch_2.setup(xPos, yPos, width, length, splitPercentage, maxSplitAngle, maxSubdivisions, maxSegments, segmentsSinceStart, angle_2, curvature, color);
        }
    }
    
    if(myLeaves.size() > 20){
        myLeaves.erase(myLeaves.begin());
    }
    ofPopMatrix();
}

//--------------------------------------------------------------
void Brunches::update(){

}

//--------------------------------------------------------------
void Brunches::draw(){
    
}
