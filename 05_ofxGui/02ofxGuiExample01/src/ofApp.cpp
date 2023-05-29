#include "ofApp.h"

void ofApp::setup() {
    ofSetFrameRate(60);
    ofBackground(0);
    ofSetCircleResolution(64);

    ofColor initColor = ofColor(0, 127, 255, 255);
    ofColor minColor = ofColor(0, 0, 0, 0);
    ofColor maxColor = ofColor(255, 255, 255, 255);

    glm::vec2 initPos = glm::vec2(ofGetWidth() / 2, ofGetHeight() / 2);
    glm::vec2 minPos = glm::vec2(0, 0);
    glm::vec2 maxPos = glm::vec2(ofGetWidth(), ofGetHeight());

    gui.setup();
    gui.add(radius.setup("radius", 200, 0, 400));
    gui.add(color.setup("color", initColor, minColor, maxColor));
    gui.add(position.setup("position", initPos, minPos, maxPos));
}

void ofApp::update() {

}

void ofApp::draw() {
    ofSetColor(color);
    ofDrawCircle(glm::vec2(position), radius);
    gui.draw();
}