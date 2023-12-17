#include "ofApp.h"

void ofApp::setup() {
    ofBackground(0);
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    fftSize = 64;
    sound.loadSound("beat.mp3");
    sound.setLoop(true);
    sound.play();
}

void ofApp::update() {
}

void ofApp::draw() {
    float * val = ofSoundGetSpectrum(fftSize);
    float hiBoost = 100.0;
    ofSetCircleResolution(32);
    // left
    for (int i = 0; i < fftSize; i++) {
        float boost = ofMap(i, 0, fftSize - 1, 1.0, hiBoost);
        float x = ofMap(i, 0, fftSize - 1, ofGetWidth()/2, 0);
        float y = ofMap(val[i] * boost, 0.0, 1.5, ofGetHeight(), 0.0);
        float width = float(ofGetWidth()) / float(fftSize) + 1;
        float hue = ofMap(i, 0, fftSize - 1, 0, 255);
        float diameter = ofMap(y, ofGetHeight(), 0, 0, ofGetHeight()/4.0);
        ofSetColor(ofColor::fromHsb(hue, 255, 64));
        ofDrawCircle(x, ofGetHeight() / 2, diameter);
        
    }
    // right
    for (int i = 0; i < fftSize; i++) {
        float boost = ofMap(i, 0, fftSize - 1, 1.0, hiBoost);
        float x = ofMap(i, 0, fftSize - 1, ofGetWidth()/2, ofGetWidth());
        float y = ofMap(val[i] * boost, 0.0, 1.5, ofGetHeight(), 0.0);
        float width = float(ofGetWidth()) / float(fftSize) + 1;
        float hue = ofMap(i, 0, fftSize - 1, 0, 255);
        float diameter = ofMap(y, ofGetHeight(), 0, 0, ofGetHeight()/4.0);
        ofSetColor(ofColor::fromHsb(hue, 255, 64));
        ofDrawCircle(x, ofGetHeight() / 2, diameter);
    }
}