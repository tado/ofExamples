#include "ofApp.h"

void ofApp::setup() {
	ofSetFrameRate(60);
	ofBackground(0);
	ofSetBackgroundAuto(false);
	ofEnableBlendMode(OF_BLENDMODE_ADD);
}

void ofApp::update() {

}

void ofApp::draw() {
	ofSetColor(255, 255, 255, 2);
	for (int i = 0; i < 100; i++) {
		walker[i].draw();
	}
}