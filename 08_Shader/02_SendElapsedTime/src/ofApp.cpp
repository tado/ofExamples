#include "ofApp.h"

void ofApp::setup() {
}

void ofApp::update() {
}

void ofApp::draw() {
    shader.load("", "shader.frag");
    shader.begin();

    // send uniform variables to shader (Elapsed time in seconds)
    shader.setUniform1f("u_time", ofGetElapsedTimef());

    ofDrawRectangle(-ofGetWidth() / 2, -ofGetHeight() / 2, ofGetWidth(), ofGetHeight());
    shader.end();
}