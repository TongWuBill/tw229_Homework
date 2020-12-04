//
//  particle system.cpp
//  3D World
//
//  Created by 吴桐 on 12/5/20.
//

#include "particle system.hpp"

FlowField::FlowField() {
    
}

FlowField::FlowField(float w, float h, float res) {
    
    width = w;
    height = h;
    resolution = res;
    
    nCols = width / resolution + 1;
    nRows = height / resolution + 1;
    
 
    int totalPts = nCols * nRows;
    
    for (int i=0; i<totalPts+10; i++)
    {
        ofVec3f flow;
        field.push_back(flow);
    }
}


void FlowField::initRandom(float scale){
    
    for (int i=0; i<field.size(); i++)
    {
        field[i].set(ofRandom(-2,2), ofRandom(-2,2));
        field[i].scale(scale);
    }
}



void FlowField::initNoise(float scale)
{

    for (int y = 0; y < nRows; y++) {
        for (int x = 0; x < nCols; x++) {
            int index = (y * nCols) + x;
            
            ofVec3f noisePos;
            noisePos.x = x*3;
            noisePos.y = y;
            noisePos.z = ofGetElapsedTimef() * scale;
           
            float noise = ofNoise(noisePos);
            noise = ofMap(noise, 0, 1, 0, TWO_PI);
            
            ofVec3f force = ofVec3f(ofNoise(noise)/6, ofNoise(noise)/6);
        
       
            force.scale(scale);
            
            field[index].set(force);
            
        }
    }
}

ofVec3f FlowField::getForceAt(ofVec3f pos){
    
    ofVec3f force;
    force.set(0,0);
    

    if (pos.x < 0 || pos.x > width || pos.y < 0 || pos.y > height)
    {
        return force;
    }
    
    // map position to grid size
    int xInd = ofMap(pos.x, 0, width, 0, nCols-1);
    int yInd = ofMap(pos.y, 0, height, 0, nRows-1);
    
    // get the index of the grid position
    int index = yInd * nCols + xInd;
    
    // get the force at the index!
    force = field[index];
    return force;
}


void FlowField::draw(float scale) {
    
    
    ofPushStyle();
    
    for (int y=0; y < nRows; y++){
        for (int x=0; x<nCols; x++){
            
            // get the index
            int index = y * nCols + x;

            // get the position
            ofVec3f pos = ofVec3f(x * resolution, y * resolution);
            
            // get the flow
            ofVec3f flow = field[index];
            
            // add the flow vector to the pos, with scale
            ofVec3f end = pos + field[index] * scale;
            
            // color the line based on direction
            float angle = atan2(flow.y, flow.x);
            float hue = ofMap( angle, -PI, PI, 0, 255);
            
            ofSetColor(ofColor::fromHsb(hue, 255, 255));
            
            // draw the flow line
            ofDrawLine(pos, end);
            
            // draw the origin pos as a dot
            ofDrawCircle(pos,1);
            
        }
    }
    
    ofPopStyle();
}

