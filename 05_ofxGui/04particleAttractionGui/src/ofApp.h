#pragma once

#include "ofMain.h"
#include "ParticleVec2.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);

    static const int num = 20000;
    ParticleVec2 particles[num];
    ofVboMesh mesh;
    bool pressed;
    
    ofxPanel gui;
    ofxFloatSlider mass;
    ofxFloatSlider friction;
    ofxFloatSlider attractForce;
};
