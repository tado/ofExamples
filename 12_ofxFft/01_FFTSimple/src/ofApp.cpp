#include "ofApp.h"

void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofBackground(0);
    fft.setup(pow(2.0, 12.0));
}

void ofApp::update(){
    fft.update();
}

void ofApp::draw(){
    vector<float> buffer;
    buffer = fft.getBins();
    ofNoFill();
    ofSetLineWidth(2.0);
    ofBeginShape();
    for (int i = 0; i < buffer.size(); i++) {
        float x = ofMap(i, 0, buffer.size(), 0, ofGetWidth());
        float y = ofMap(buffer[i], 0, 1, ofGetHeight(), 0);
        ofVertex(x, y);
    }
    ofEndShape();
}