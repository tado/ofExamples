#include "ofApp.h"

void ofApp::setup() {

}

void ofApp::update() {
    location.push_back(glm::vec3(ofGetWidth() / 2.0, ofGetHeight() / 2.0, 0));
    velocity.push_back(glm::vec3(ofRandom(-5, 5), ofRandom(-5, 5), ofRandom(-5, 5)));

    for (int i = 0; i < location.size(); i++) {
        location[i] = location[i] + velocity[i];
        if (location[i].x > ofGetWidth() || location[i].x < 0) {
            velocity[i].x = velocity[i].x * -1;
        }
        if (location[i].y > ofGetHeight() || location[i].y < 0) {
            velocity[i].y = velocity[i].y * -1;
        }
        if (location[i].z > ofGetHeight()/2 || location[i].z < -ofGetHeight()/2) {
            velocity[i].z = velocity[i].z * -1;
        }
    }
}

void ofApp::draw() {
    ofSetColor(31, 127, 255);
    for (int i = 0; i < location.size(); i++) {
        ofDrawCircle(location[i], 10);
    }
    ofSetColor(255);
    ofDrawBitmapString(location.size(), 10, 20);
    ofDrawBitmapString(ofGetFrameRate(), 10, 40);
}