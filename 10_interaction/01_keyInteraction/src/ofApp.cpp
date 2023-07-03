#include "ofApp.h"

void ofApp::setup() {
	ofBackground(0);
	showStatus = false;
}

void ofApp::update() {
}

void ofApp::draw() {
	cam.begin();
	float radius = sin(ofGetElapsedTimef() * 8.0) * 200 + 250;
	ofSpherePrimitive sphere;
	sphere.set(radius, 32);
	sphere.drawWireframe();
	cam.end();

	if (showStatus) {
		ofDrawBitmapStringHighlight("frameRate = " + ofToString(ofGetFrameRate()), 20, 20);
	}
}

void ofApp::keyPressed(int key) {
}

void ofApp::keyReleased(int key) {
	if (key == 'f') {
		ofToggleFullscreen();
	}
	if (key == 'd') {
		if (showStatus) {
			showStatus = false;
		}
		else {
			showStatus = true;
		}
	}
}
