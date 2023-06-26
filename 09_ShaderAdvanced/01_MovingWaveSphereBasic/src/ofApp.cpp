#include "ofApp.h"

void ofApp::setup() {
    sphere.set(200, 32);
}

void ofApp::update() {
}

void ofApp::draw() {
    shader.load("shader.vert", "shader.frag");
    cam.begin();
    shader.begin();
    // send uniform variables to shader (Elapsed time in seconds)
    shader.setUniform1f("u_time", ofGetElapsedTimef());
    // send uniform variables to shader (resolution)
    shader.setUniform2f("u_resolution", ofGetWidth(), ofGetHeight());
    sphere.draw();
    shader.end();
    cam.end();
}