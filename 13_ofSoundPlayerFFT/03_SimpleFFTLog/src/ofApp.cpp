#include "ofApp.h"

void ofApp::setup() {
    fftSize = 512;
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
    ofVertex(0, ofGetHeight());
    for (int i = 0; i < fftSize; i++) {
        float x = ofMap(i, 0, fftSize - 1, 0, ofGetWidth());
        float y = ofMap(val[i], 0.0, 1.5, ofGetHeight(), 0.0);
        float logX = ofMap(log10(x), 0, log10f(ofGetWidth()), 0, ofGetWidth());
        float logY = ofMap(log10f(y), 0, log10f(ofGetHeight()), 0, ofGetHeight()); 
        if (val[i] > 0.0) {
            ofVertex(logX, y);
        }
    }
    ofEndShape();
}