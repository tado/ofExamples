#include "ofApp.h"

void ofApp::setup() {
    locationX = ofGetWidth() / 2;
    locationY = ofGetHeight() / 2;
    velocityX = 3;
    velocityY = 2;
}

void ofApp::update() {
    locationX = locationX + velocityX;
    locationY = locationY + velocityY;
}

void ofApp::draw() {
    ofSetColor(31, 127, 255);
    ofDrawCircle(locationX, locationY, 20);
}