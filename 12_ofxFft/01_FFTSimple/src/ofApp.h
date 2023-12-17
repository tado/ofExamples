#pragma once

#include "ofMain.h"
#include "ofxEasyFft.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();

    ofxEasyFft fft;
};
