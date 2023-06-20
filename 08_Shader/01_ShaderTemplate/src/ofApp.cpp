#include "ofApp.h"

void ofApp::setup() {
}

void ofApp::update() {
}

void ofApp::draw() {
    shader.load("", "shader.frag");
    shader.begin();
    ofDrawRectangle(-ofGetWidth() / 2, -ofGetHeight() / 2, ofGetWidth(), ofGetHeight());
    shader.end();
}