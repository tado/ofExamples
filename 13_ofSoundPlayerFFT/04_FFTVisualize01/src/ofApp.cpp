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
    // left
    for (int i = 0; i < fftSize; i++) {
        float hiBoost = ofMap(i, 0, fftSize - 1, 1.0, 10.0);
        float x = ofMap(i, 0, fftSize - 1, ofGetWidth()/2, 0);
        float y = ofMap(val[i] * hiBoost, 0.0, 1.5, ofGetHeight(), 0.0);
        float width = float(ofGetWidth()) / float(fftSize) + 1;
        float hue = ofMap(i, 0, fftSize - 1, 0, 255);
        ofSetColor(ofColor::fromHsb(hue, 255, 255));
        ofDrawRectangle(x, y, width, ofGetHeight() - y);
    }
    // right
    for (int i = 0; i < fftSize; i++) {
        float hiBoost = ofMap(i, 0, fftSize - 1, 1.0, 10.0);
        float x = ofMap(i, 0, fftSize - 1, ofGetWidth()/2, ofGetWidth());
        float y = ofMap(val[i] * hiBoost, 0.0, 1.5, ofGetHeight(), 0.0);
        float width = float(ofGetWidth()) / float(fftSize) + 1;
        float hue = ofMap(i, 0, fftSize - 1, 0, 255);
        ofSetColor(ofColor::fromHsb(hue, 255, 255));
        ofDrawRectangle(x, y, width, ofGetHeight() - y);
    }
}