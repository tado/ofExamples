#include "ofApp.h"

void ofApp::setup(){
    cam.initGrabber(640, 480);
}

void ofApp::update(){
    cam.update();
}

void ofApp::draw(){
    cam.draw(20, 20);
}
