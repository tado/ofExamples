#pragma once

#include "ofMain.h"
#include "ofxBox2d.h"

class ofApp : public ofBaseApp {

public:
    void setup();
    void update();
    void draw();

    ofxBox2d box2d;
    ofxBox2dCircle circle;
    ofxBox2dRect rect;
};
