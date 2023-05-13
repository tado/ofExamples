#include "ofApp.h"

void ofApp::setup() {
    ofEnableDepthTest();

    light.enable();
    light.setPosition(-300, 300, 500);

    material.setAmbientColor(ofColor(127, 63, 31));
    material.setDiffuseColor(ofColor(0, 127, 255));
    material.setSpecularColor(ofColor(255, 255, 0, 255));
    material.setShininess(120);
    material.setEmissiveColor(ofColor(97, 0, 0));
}

void ofApp::update() {
}

void ofApp::draw() {
    material.begin();
    cam.begin();

    ofSetColor(255);

    box.set(200);
    box.setPosition(-150, 0, 0);
    box.draw();

    sphere.set(100, 16);
    sphere.setPosition(150, 0, 0);
    sphere.draw();

    cam.end();
    material.end();
}