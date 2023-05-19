#pragma once

#include "ofMain.h"
#include "RandomWalker.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    RandomWalker walker[100];
};
