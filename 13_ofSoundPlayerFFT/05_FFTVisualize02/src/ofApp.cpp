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
    float hiBoost = 40.0;
    // left
    for (int i = 0; i < fftSize; i++) {
        float boost = ofMap(i, 0, fftSize - 1, 1.0, hiBoost);
        float x = ofMap(i, 0, fftSize - 1, ofGetWidth()/2, 0);
        float y = ofMap(val[i] * boost, 0.0, 1.5, ofGetHeight(), 0.0);
        float width = float(ofGetWidth()) / float(fftSize) + 1;
        float hue = ofMap(i, 0, fftSize - 1, 0, 255);
        float brightness = ofMap(y, ofGetHeight(), 0, 0, 255);
        ofSetColor(ofColor::fromHsb(hue, 255, brightness));
        ofDrawRectangle(x, 0, width, ofGetHeight());
    }
    // right
    for (int i = 0; i < fftSize; i++) {
        float boost = ofMap(i, 0, fftSize - 1, 1.0, hiBoost);
        float x = ofMap(i, 0, fftSize - 1, ofGetWidth()/2, ofGetWidth());
        float y = ofMap(val[i] * boost, 0.0, 1.5, ofGetHeight(), 0.0);
        float width = float(ofGetWidth()) / float(fftSize) + 1;
        float hue = ofMap(i, 0, fftSize - 1, 0, 255);
        float brightness = ofMap(y, ofGetHeight(), 0, 0, 255);
        ofSetColor(ofColor::fromHsb(hue, 255, brightness));
        ofDrawRectangle(x, 0, width, ofGetHeight());
    }
}