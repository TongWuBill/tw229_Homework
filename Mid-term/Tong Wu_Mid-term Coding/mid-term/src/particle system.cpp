//
//  particle system.cpp
//  mid-term
//
//  Created by 侯丁瑞 on 2020/11/22.
//

#include "particle system.hpp"

FlowField::FlowField() {
    
}

FlowField::FlowField(float _width, float _height, float _resolution) {
    
    width = _width;
    height = _height;
    resolution = _resolution;
    
    nCols = width / resolution;
    nRows = height / resolution;
    
 
    int totalPts = nCols * nRows;
    
    for (int i=0; i<totalPts; i++)
    {
        ofVec3f flow;
        field.push_back(flow);
    }
}


void FlowField::initRandom(float scale){
    
    for (int i=0; i<field.size(); i++)
    {
        field[i].set(ofRandom(-10,10), ofRandom(-20,20));
        field[i].scale(scale);
    }
}



void FlowField::initNoise(float scale)
{

    for (int y = 0; y < nRows; y++) {
        for (int x = 0; x < nCols; x++) {
            int index = (y * nCols) + x;
            
            ofVec3f noisePos;
            noisePos.x = x*20;
            noisePos.y = y*1.2;
           
            float noise = ofNoise(noisePos);
            noise = ofMap(noise, 0, 1, 0, TWO_PI);
            
            ofVec3f force = ofVec3f(sin(noise), cos(noise*2));
        
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


