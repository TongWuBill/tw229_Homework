//
//  particle.hpp
//  3D World
//
//  Created by 吴桐 on 12/5/20.
//


#ifndef particle_hpp
#define particle_hpp

#include "ofMain.h"
#include "ofxAssimpModelLoader.h"

#endif /* particle_hpp */

class Particle {
    
public:

    Particle();

     
    Particle(ofVec3f _pos, ofVec3f _vel);
    
    void applyForce(ofVec3f force);
    void applyDamping(float strength);
    
    void update();
    void draw();
    
    float radius = ofRandom(4,8);
    
    ofVec3f pos, vel, acc;
    
    ofxAssimpModelLoader yourModel;
};
