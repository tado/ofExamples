#include "ofApp.h"

void ofApp::setup() {
	ofBackground(0);
	ofSetFrameRate(60);
	currentPos = glm::vec2(ofGetWidth() / 2, ofGetHeight() / 2);
}

void ofApp::update() {
	toPos = glm::vec2(mouseX, mouseY);
	currentPos += (toPos - currentPos) * 0.1;
}

void ofApp::draw() {
	ofDrawCircle(currentPos, 20);
}