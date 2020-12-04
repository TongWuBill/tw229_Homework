//
//  particle system.hpp
//  3D World
//
//  Created by 吴桐 on 12/5/20.
//


#ifndef particle_system_hpp
#define particle_system_hpp

#include "ofMain.h"

#endif /* particle_system_hpp */

class FlowField {
    
public:
    
    FlowField();
    ~FlowField(){}
    
    FlowField(float w, float h, float res);
    
    void initRandom(float scale);
    void initNoise(float scale);
    
   ofVec3f getForceAt(ofVec3f pos);
    
    void draw(float scale);
  
    vector<ofVec3f> field;
    
    int nCols, nRows;

    float width, height, resolution;
};
