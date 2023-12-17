#include "ofApp.h"

void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofBackground(0);
    fft.setup(pow(2.0, 12.0));
    gui.setup();
    gui.add(saturation.setup("Saturation", 127, 0, 255));
    gui.loadFromFile("settings.xml");
}

void ofApp::update(){
    fft.update();
}

void ofApp::draw(){
    vector<float> buffer;
    buffer = fft.getBins();
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofSetLineWidth(ofGetWidth() / float(buffer.size()));
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < buffer.size(); i++) {
            float hue = ofMap(i, 0, buffer.size(), 0, 160);
            float br = ofMap(buffer[i], 0, 1, 0, 255);
            ofColor col;
            col.setHsb(hue, saturation, br);
            ofSetColor(col);
            float rx = ofMap(i, 0, buffer.size(), 0, ofGetWidth() / 2.0);
            ofDrawLine(rx, -ofGetWidth() / 2.0, rx, ofGetWidth() / 2.0);
            float lx = ofMap(i, 0, buffer.size(), 0, -ofGetWidth() / 2.0);
            ofDrawLine(lx, -ofGetWidth() / 2.0, lx, ofGetWidth() / 2.0);
        }
        ofRotateZDeg(90);
    }
    ofPopMatrix();
    gui.draw();
}