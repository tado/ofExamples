#pragma once

#include "ofMain.h"
#include "ofxEasyFft.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();    
    
    ofxEasyFft fft;
    ofxPanel gui;
    ofxFloatSlider alpha;
    ofxFloatSlider saturation;
    ofxFloatSlider radiusMax;
};
