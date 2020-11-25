//
//  particle system.hpp
//  mid-term
//
//  Created by 侯丁瑞 on 2020/11/22.
//

#ifndef particle_system_hpp
#define particle_system_hpp

#include "ofMain.h"

#endif /* particle_system_hpp */

class FlowField {
    
public:
    
    FlowField();
    ~FlowField(){}
    
    FlowField(float _width, float _height, float _resolution);
    
    void initRandom(float scale);
    void initNoise(float scale);
    
   ofVec3f getForceAt(ofVec3f pos);
    
  
  
    vector<ofVec3f> field;
    
    int nCols, nRows;

    float width, height, resolution;    
};
