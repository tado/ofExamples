#pragma once

#include "ofMain.h"
#include "ofxProcessFFT.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp {
public:
    void setup();
    void update();
    void draw();
    
    ProcessFFT fft;
    ofxPanel gui;
    ofxFloatSlider level;
};
