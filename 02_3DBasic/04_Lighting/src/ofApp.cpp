#include "ofApp.h"

void ofApp::setup() {
    ofEnableDepthTest();
    light.enable();
    light.setPosition(-300, 300, 500);
}

void ofApp::update() {
}

void ofApp::draw() {
    cam.begin();

    ofSetColor(255);

    box.set(200);
    box.setPosition(-150, 0, 0);
    box.draw();

    sphere.set(100, 16);
    sphere.setPosition(150, 0, 0);
    sphere.draw();

    cam.end();
}