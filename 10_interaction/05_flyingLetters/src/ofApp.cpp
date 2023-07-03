#include "ofApp.h"

void ofApp::setup(){
	ofBackground(0);
	delayLength = 30;
}

void ofApp::update(){
    glm::vec2 pos = glm::vec2(mouseX, mouseY);
    mousePos.push_back(pos);
    if (mousePos.size() > delayLength) {
        mousePos.erase(mousePos.begin());
    }
}

void ofApp::draw(){
    ofDrawCircle(mousePos[0], 20);
}