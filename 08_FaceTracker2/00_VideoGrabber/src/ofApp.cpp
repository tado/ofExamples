#include "ofApp.h"

void ofApp::setup() {
    ofSetFrameRate(60);
    //grabber.listDevices();
    //grabber.setDeviceID(0);
    grabber.setDesiredFrameRate(60);
    grabber.initGrabber(640, 360);
}

void ofApp::update() {
    grabber.update();
}

void ofApp::draw() {
    grabber.draw(0, 0, ofGetWidth(), ofGetHeight());
}
