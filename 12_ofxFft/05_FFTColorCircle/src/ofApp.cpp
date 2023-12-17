#include "ofApp.h"

void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(0);
    fft.setup(pow(2.0, 10.0));
    gui.setup();
    gui.add(saturation.setup("Saturation", 127, 0, 255));
    gui.add(alpha.setup("Alpha", 127, 0, 255));
    gui.add(radiusMax.setup("Radius Max", 1000, 0, 2000));
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
    ofSetLineWidth(ofGetWidth() / float(buffer.size()) / 2.0);
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    ofSetCircleResolution(64);
    for (int i = 0; i < buffer.size(); i++) {
        float hue = ofMap(i, 0, buffer.size(), 0, 160);
        float br = ofMap(buffer[i], 0, 1, 0, 255);
        float radius = ofMap(buffer[i], 0, 1, 0, radiusMax);
        ofColor col;
        col.setHsb(hue, saturation, br, alpha);
        ofSetColor(col);
        float rx = ofMap(i, 0, buffer.size(), 0, ofGetWidth() / 2.0);
        ofDrawCircle(rx, 0, radius);
        float lx = ofMap(i, 0, buffer.size(), 0, -ofGetWidth() / 2.0);
        ofDrawCircle(lx, 0, radius);
    }
    ofPopMatrix();
    gui.draw();
}