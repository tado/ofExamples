#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp {

public:
    void setup();
    void update();
    void draw();

    ofxPanel gui;
    ofxFloatSlider radius;
    ofxColorSlider color;
    ofxVec2Slider position;
};
