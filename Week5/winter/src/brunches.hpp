//
//  brunches.hpp
//  seasonal change
//
//  Created by 吴桐 on 11/27/20.
//

#ifndef brunches_hpp
#define brunches_hpp

#include "ofMain.h"
#include "leaves.hpp"

class Brunches : public ofBaseApp{

    public:
        void setup(
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
                   ofColor _color
        );
    
        void update();
        void draw();
    
    
   
        float xPos, yPos;
        float width,length;
        float splitPercentage;
        float maxSplitAngle;
        float maxSubdivisions;
        float maxSegments;
        float segmentsSinceStart;
        float angle;
        float curvature;
        ofColor color;
      
    
        int numLeaves;
        vector<Leaf> myLeaves;
    
};

#endif 
