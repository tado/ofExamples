#include "ofApp.h"

void ofApp::setup() {
	ofSetFrameRate(60);
	ofBackground(0);
	pos.x = ofGetWidth() / 2;
	pos.y = ofGetHeight() / 2;
}

void ofApp::update() {
}

void ofApp::draw() {
	pos.x += ofRandom(-1, 1);
	pos.y += ofRandom(-1, 1);
	ofSetColor(255);
	ofDrawCircle(pos.x, pos.y, 2);
}