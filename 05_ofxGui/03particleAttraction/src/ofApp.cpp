#include "ofApp.h"

void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(0);
    mesh.setMode(OF_PRIMITIVE_POINTS);
    pressed = false;
    for (int i = 0; i < num; i++) {
        particles[i].position = ofVec2f(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
    }
}

void ofApp::update(){
    mesh.clear();
    for (int i = 0; i < num; i++) {
        if (pressed) {
            particles[i].addAttractionForce(mouseX, mouseY, 1000, 1.0);
        }
        particles[i].update();
        particles[i].throughOffWalls();
        mesh.addVertex(ofVec3f(particles[i].position.x, particles[i].position.y));
    }
}

void ofApp::draw(){
    mesh.draw();
}

void ofApp::mousePressed(int x, int y, int button){
    pressed = true;
}

void ofApp::mouseReleased(int x, int y, int button){
    pressed = false;
}