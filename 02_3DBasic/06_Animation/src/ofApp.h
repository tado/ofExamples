#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();

    ofBoxPrimitive box[256];
    ofEasyCam cam;
    ofLight light;
    ofMaterial material;
};
