#include "ofApp.h"

void ofApp::setup() {
	ofBackground(0);
	delayLength = 30;
	skip = 10;
}

void ofApp::update() {
	glm::vec2 pos = glm::vec2(mouseX, mouseY);
	mousePos.push_back(pos);
	if (mousePos.size() > delayLength) {
		mousePos.erase(mousePos.begin());
	}
}

void ofApp::draw() {
	for (int i = 0; i < mousePos.size(); i += skip) {
		ofDrawCircle(mousePos[i], 20);
	}
}