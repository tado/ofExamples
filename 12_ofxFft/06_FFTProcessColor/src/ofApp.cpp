#include "ofApp.h"

void ofApp::setup() {
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofBackground(0);
    fft.setup();
    fft.setNumFFTBins(16);
    fft.setNormalize(true);
    gui.setup();
    gui.add(level.setup("Input Level", 500, 0, 5000));
    gui.loadFromFile("settings.xml");
}

void ofApp::update() {
    fft.update();
}

void ofApp::draw() {
    float lowValue = ofMap(fft.getLowVal(), 0, 1, 0, level);
    float midValue = ofMap(fft.getMidVal(), 0, 1, 0, level);
    float highValue = ofMap(fft.getHighVal(), 0, 1, 0, level);
    ofSetColor(lowValue, midValue, highValue);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    gui.draw();
}
