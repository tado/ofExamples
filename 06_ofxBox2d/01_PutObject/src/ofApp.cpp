#include "ofApp.h"

void ofApp::setup() {
    box2d.init();
    box2d.setFPS(30);
    box2d.createBounds();
    box2d.registerGrabbing();

    circle.setPhysics(1.0, 0.5, 0.1);
    circle.setup(box2d.getWorld(), ofGetWidth() / 3, 100, 40);

    rect.setPhysics(2.0, 0.5, 0.1);
    rect.setup(box2d.getWorld(), ofGetWidth() / 3 * 2, 100, 100, 40);
}

void ofApp::update() {
    box2d.update();
}

void ofApp::draw() {
    circle.draw();
    rect.draw();
}
