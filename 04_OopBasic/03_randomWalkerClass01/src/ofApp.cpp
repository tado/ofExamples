#include "ofApp.h"

void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(0);
    ofSetBackgroundAuto(false);
    ofEnableBlendMode(OF_BLENDMODE_ADD);
}

void ofApp::update(){
}

void ofApp::draw(){
    ofSetColor(255, 255, 255, 5);
    walker.draw();
}
