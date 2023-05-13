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
	for (int i = 0; i < myMesh.getVertices().size(); i++) {
		glm::vec3 loc = myMesh.getVertices()[i];
		float div1 = 800.0;
		float div2 = 200.0;
		float noise1 = ofMap(ofNoise(loc.x / div1, loc.y / div1, loc.z / div1, ofGetElapsedTimef()), 0, 1, 40, 180);
		float noise2 = ofMap(ofNoise(loc.x / div2, loc.y / div2, loc.z / div2, ofGetElapsedTimef()), 0, 1, 60, 120);
		float noise = noise1 + noise2;
		glm::vec3 newLoc = glm::normalize(loc) * noise;
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