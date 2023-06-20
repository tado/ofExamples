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
    // send uniform variables to shader (resolution)
    shader.setUniform2f("u_resolution", ofGetWidth(), ofGetHeight());

    ofRect(-ofGetWidth() / 2, -ofGetHeight() / 2, ofGetWidth(), ofGetHeight());
    shader.end();
}