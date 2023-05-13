#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp {

public:
    void setup();
    void update();
    void draw();

    float locationX;
    float locationY;
    float velocityX;
    float velocityY;
};
