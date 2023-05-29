#pragma once

#include "ofMain.h"
#include "ParticleVec2.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    
    static const int num = 50000;
    ParticleVec2 particles[num];
    ofVboMesh mesh;
    bool pressed;
};
