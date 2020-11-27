//
//  leaves.hpp
//  seasonal change
//
//  Created by 吴桐 on 11/27/20.
//

#ifndef leaves_hpp
#define leaves_hpp

#include "ofMain.h"

class Leaf {
    
public:
    void setup();
    void update();
    void draw(float _xPos, float _yPos,  int _segmentsSinceStart);
    

    float xPos, yPos;
    
    float leafWidth, leafHeight;
    float stemWidth, stemHeight;
    
    ofColor leafColorLeft, leafColorRight, stemColor, fruitColorOne, fruitColorTwo;
    
    float rotation;
    
    float scaleFactor;
    

    int segmentsSinceStart;
    
    ofColor flowerColor;
    int flowerRotate;
    
    
};

#endif /* defined(__Leaf__Leaf__) */
