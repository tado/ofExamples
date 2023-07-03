#include "ofApp.h"

void ofApp::setup() {
	ofBackground(0);
	ofSetFrameRate(60);
	delayLength = 240;
	skip = 5;
}

void ofApp::update() {
	glm::vec2 pos = glm::vec2(mouseX, mouseY);
	mousePos.push_back(pos);
	if (mousePos.size() > delayLength) {
		mousePos.erase(mousePos.begin());
	}
}

void ofApp::draw() {
	ofNoFill();
	ofEnableSmoothing();
	ofSetCircleResolution(64);
	for (int i = 0; i < mousePos.size(); i += skip) {
		ofDrawCircle(mousePos[i], mousePos.size() - i + 4);
	}
}