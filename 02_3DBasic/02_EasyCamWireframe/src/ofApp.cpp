#include "ofApp.h"

void ofApp::setup() {
}

void ofApp::update() {

}

void ofApp::draw() {
    cam.begin();  
    
    box.set(200);
    box.setPosition(-150, 0, 0);
    box.drawWireframe();

    sphere.set(100, 16);
    sphere.setPosition(150, 0, 0);
    sphere.drawWireframe();

    cam.end();
}