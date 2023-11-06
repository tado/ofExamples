#include "ofApp.h"

void ofApp::setup() {
    ofBackground(0);
    ofPlanePrimitive plane;
    plane.set(1000, 1000, 100, 100);
    mesh = plane.getMesh();
}

void ofApp::update() {
    float freq = 0.02;
    float scale = 50.0;
    vector<glm::vec3> verties = mesh.getVertices();
    for (int i = 0; i < verties.size(); i++) {
        float x = verties[i].x;
        float y = verties[i].y;
        float zx = sin(ofGetElapsedTimef() + x * freq) * scale;
        float zy = cos(ofGetElapsedTimef() + y * freq) * scale;
        float z = zx + zy;
        mesh.setVertex(i, glm::vec3(x, y, z));
    }
}

void ofApp::draw() {
    cam.begin();
    ofPushMatrix();
    ofRotateXDeg(-45);
    //mesh.setMode(OF_PRIMITIVE_POINTS);
    //glPointSize(3.0);
    mesh.drawWireframe();
    ofPopMatrix();
    cam.end();
}