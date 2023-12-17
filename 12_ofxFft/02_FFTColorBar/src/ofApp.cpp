#include "ofApp.h"

void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofBackground(0);
    fft.setup(pow(2.0, 8.0));
}

void ofApp::update(){
    fft.update();
}

void ofApp::draw(){
    vector<float> buffer;
    buffer = fft.getBins();

    ofSetLineWidth(ofGetWidth() / float(buffer.size()) / 2.0 - 0.5);
    for (int i = 0; i < buffer.size(); i++) {
        float hue = ofMap(i, 0, buffer.size(), 0, 160);
        ofColor col;
        col.setHsb(hue, 255, 255);
        ofSetColor(col);
        float rx = ofMap(i, 0, buffer.size(), ofGetWidth() / 2.0, ofGetWidth());
        float y = ofMap(buffer[i], 0, 1, ofGetHeight(), 0);
        ofDrawLine(rx, ofGetHeight(), rx, y);
        float lx = ofMap(i, 0, buffer.size(), ofGetWidth() / 2.0, 0);
        ofDrawLine(lx, ofGetHeight(), lx, y);
    }
}