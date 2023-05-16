#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp {

public:
    void setup();
    void update();
    void draw();

    vector<glm::vec3> location;
    vector<glm::vec3> velocity;
    vector<ofSpherePrimitive> sphere;
    ofLight light;
    ofMaterial material;
    ofEasyCam cam;
};
