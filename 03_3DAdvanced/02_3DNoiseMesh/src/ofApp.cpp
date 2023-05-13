#include "ofApp.h"

void ofApp::setup() {
	ofBackground(0);
	ofPlanePrimitive plane;
	plane.set(1000, 1000, 100, 100);
	mesh = plane.getMesh();
}

void ofApp::update() {
	float div = 400.0;
	float scale = 200.0;
	float speed = 0.25;
	for (int i = 0; i < mesh.getVertices().size(); i++) {
		float x = mesh.getVertices()[i].x;
		float y = mesh.getVertices()[i].y;
		float z = ofNoise(x / div, y / div, ofGetElapsedTimef() * speed) * scale;
		mesh.setVertex(i, glm::vec3(x, y, z));
	}
}

void ofApp::draw() {
	cam.begin();
	ofPushMatrix();
	ofRotateXDeg(-45);
	mesh.setMode(OF_PRIMITIVE_POINTS);
	glPointSize(3.0);
	mesh.draw();
	ofPopMatrix();
	cam.end();
}