#include "ofApp.h"

void ofApp::setup() {
    ofSetFrameRate(60);
    ofBackground(0);
    ofSetCircleResolution(64);
}

void ofApp::update() {

}

void ofApp::draw() {
    ofSetColor(31, 127, 255);
    ofDrawCircle(glm::vec2(ofGetWidth() / 2, ofGetHeight() / 2), 200);
}