#include "ofApp.h"

void ofApp::setup() {
    ofSetFrameRate(60);
    ofBackground(0);
    mesh.setMode(OF_PRIMITIVE_POINTS);
    pressed = false;
    for (int i = 0; i < num; i++) {
        particles[i].position = ofVec2f(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
    }

    gui.setup();
    gui.add(mass.setup("mass", 2.0, 0.0, 5.0));
    gui.add(friction.setup("friction", 0.01, 0.0, 0.03));
    gui.add(attractForce.setup("attractForce", 1.0, 0.0, 5.0));
}

void ofApp::update() {
    mesh.clear();
    for (int i = 0; i < num; i++) {
        particles[i].mass = mass;
        particles[i].friction = friction;
        if (pressed) {
            particles[i].addAttractionForce(mouseX, mouseY, 1000, attractForce);
        }
        particles[i].update();
        particles[i].throughOffWalls();
        mesh.addVertex(ofVec3f(particles[i].position.x, particles[i].position.y));
    }
}

void ofApp::draw() {
    glPointSize(mass);
    mesh.draw();
    gui.draw();
}

void ofApp::mousePressed(int x, int y, int button) {
    pressed = true;
}

void ofApp::mouseReleased(int x, int y, int button) {
    pressed = false;
}