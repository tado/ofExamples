#include "ofApp.h"

void ofApp::setup() {
    ofSetFrameRate(60);
    ofBackground(0);
    ofIcoSpherePrimitive sphere;
    sphere.setRadius(400);
    sphere.setResolution(4);
    myMesh = sphere.getMesh();
    for (int i = 0; i < myMesh.getVertices().size(); i++) {
        myMesh.addColor(ofFloatColor(1.0, 1.0, 1.0, 1.0));
    }
}

void ofApp::update() {
    vector<glm::vec3> vertices = myMesh.getVertices();
    for (int i = 0; i < vertices.size(); i++) {
        float div1 = 800.0;
        float div2 = 200.0;
        float noise1 = ofMap(ofNoise
        (
            vertices[i].x / div1,
            vertices[i].y / div1,
            vertices[i].z / div1,
            ofGetElapsedTimef()
        ), 0, 1, 40, 180);
        float noise2 = ofMap(ofNoise
        (
            vertices[i].x / div2,
            vertices[i].y / div2,
            vertices[i].z / div2,
            ofGetElapsedTimef()
        ), 0, 1, 60, 120);
        float noise = noise1 + noise2;
        glm::vec3 newLoc = glm::normalize(vertices[i]) * noise;
        myMesh.setVertex(i, newLoc);
    }
}

void ofApp::draw() {
    cam.begin();
    ofPushMatrix();
    ofRotateYDeg(ofGetElapsedTimef() * 10.0);
    myMesh.drawWireframe();
    ofPopMatrix();
    cam.end();
}