#include "ofApp.h"

void ofApp::setup() {
    ofEnableDepthTest();

    light.enable();
    light.setPosition(-100, 100, 500);

    material.setAmbientColor(ofColor(255, 255, 127));
    material.setDiffuseColor(ofColor(0, 127, 255));
    material.setSpecularColor(ofColor(255, 255, 255));
    material.setShininess(120);
}

void ofApp::update() {
}

void ofApp::draw() {
    material.begin();
    cam.begin();

    for (int i = 0; i < 256; i++) {
        ofPushMatrix();
        ofRotateXDeg(i * 1.2 + ofGetElapsedTimef() * 10.0);
        ofRotateYDeg(i * 2.2 + ofGetElapsedTimef() * 13.0);
        box[i].set(300);
        box[i].draw();
        ofPopMatrix();
    }

    cam.end();
    material.end();
}