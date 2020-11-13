//
//  asteroids.hpp
//  interstellar
//
//  Created by 吴桐 on 11/13/20.
//

#ifndef asteroids_hpp
#define asteroids_hpp

#include "ofMain.h"

#endif /* asteroids_hpp */

class Asteroids{
public:
    Asteroids();
    Asteroids(glm::vec2 _pos,float _mass);
    
    void applyForce(glm::vec2 force);
    void applyDampingForce(float strength);
    void bounceWindowEdges();
    void update();
    void draw();
    glm::vec2 pos, vel, acc;
    float mass;
};
