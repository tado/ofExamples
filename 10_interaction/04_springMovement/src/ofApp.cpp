#include "ofApp.h"

void ofApp::setup() {
	ofSetFrameRate(60);
	ofBackground(0);
	currentPos = glm::vec2(ofGetWidth() / 2, ofGetHeight() / 2);
	velocity = glm::vec2(0, 0);
	stiffness = 0.05;
	friction = 0.95;
	mass = 1.0;
}

void ofApp::update() {
	toPos = glm::vec2(mouseX, mouseY);
	glm::vec2 force = stiffness * (toPos - currentPos);
	glm::vec2 accel = force / mass;
	velocity = friction * (velocity + accel);
	currentPos += velocity;
}

void ofApp::draw() {
	ofSetColor(255);
	ofDrawCircle(currentPos, 20);
	ofSetColor(190);
	ofDrawLine(currentPos, toPos);
}
