#include "ofApp.h"

void ofApp::setup() {
    fftSize = 1024;
    sound.loadSound("beat.mp3");
    sound.setLoop(true);
    sound.play();
}

void ofApp::update() {
}

void ofApp::draw() {
    float * val = ofSoundGetSpectrum(fftSize);
    ofNoFill();
    ofBeginShape();
    for (int i = 0; i < fftSize; i++) {
        float x = ofMap(i, 0, fftSize - 1, 0, ofGetWidth());
        float y = ofMap(val[i], 0, 1.0, ofGetHeight(), 0.0);
        ofVertex(x, y);
    }
    ofEndShape();
}