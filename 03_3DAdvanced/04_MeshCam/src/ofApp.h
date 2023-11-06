#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp {
public:
    void setup();
    void update();
    void draw();
    void keyPressed(int key);

    int meshWidth;
    int meshHeight;
    int num_particles;

    ofEasyCam cam;
    ofLight light;
    ofVboMesh mesh;
    ofVideoGrabber myVideo;
};
