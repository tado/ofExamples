#include "ofApp.h"

void ofApp::setup() {
    ofEnableDepthTest();
}

void ofApp::update() {
}

void ofApp::draw() {
    shader.load("shader.vert", "shader.frag");
    cam.begin();
    shader.begin();
    shader.setUniform1f("u_time", ofGetElapsedTimef());
    shader.setUniform2f("u_resolution", ofGetWidth(), ofGetHeight());
    sphere.set(ofGetHeight() / 2.5, 32);
    sphere.draw();
    shader.end();
    cam.end();
}