#include "ofApp.h"

void ofApp::setup() {
	ofBackground(0);
	circleColor = ofColor(31, 127, 255);
}

void ofApp::update() {
}

void ofApp::draw() {
	ofSetColor(circleColor);
	ofSetCircleResolution(64);
	ofDrawCircle(mouseX, mouseY, 100);
}

void ofApp::mousePressed(int x, int y, int button) {
	circleColor = ofColor(255, 127, 31);
}

void ofApp::mouseReleased(int x, int y, int button) {
	circleColor = ofColor(31, 127, 255);

}
