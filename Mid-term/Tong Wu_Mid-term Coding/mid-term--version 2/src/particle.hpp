//
//  particle.hpp
//  mid-term
//
//  Created by 侯丁瑞 on 2020/11/22.
//

#ifndef particle_hpp
#define particle_hpp

#include "ofMain.h"

#endif /* particle_hpp */

class Particle {
    
public:

    Particle();

     
    Particle(ofVec3f _pos, ofVec3f _vel);
    
    void applyForce(ofVec3f force);
    void applyDamping(float strength);
    
    void update();
    void draw();
    
    float radius = ofRandom(0.5,1);
    
    ofVec3f pos, vel, acc;
    
};
