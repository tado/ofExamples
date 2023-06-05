#pragma once

#include "ofMain.h"
#include "ofxBox2d.h"

class ofApp : public ofBaseApp {

public:
    void setup();
    void update();
    void draw();
    void mouseDragged(int x, int y, int button);

    ofxBox2d box2d;
    vector<ofPtr<ofxBox2dCircle>> circles;
    vector<ofPtr<ofxBox2dRect>> rects;
};
