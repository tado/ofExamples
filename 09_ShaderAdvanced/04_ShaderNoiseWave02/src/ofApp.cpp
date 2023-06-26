#include "ofApp.h"

void ofApp::setup() {
	ofSetFrameRate(60);
	ofBackground(0);
	ofPlanePrimitive plane;
	plane.set(2500, 2500, 200, 200);
	mesh = plane.getMesh();
	shader.load("shader");
}

void ofApp::update() {
	float div = 400.0;
	float scale = 400.0;
	float speed = 0.5;
	for (int i = 0; i < mesh.getVertices().size(); i++) {
		glm::vec3 pos = mesh.getVertices()[i];
		pos.z = ofNoise(pos.x / div, pos.y / div, ofGetElapsedTimef() * speed) * scale;
		mesh.setVertex(i, pos);
	}
}

void ofApp::draw() {
	ofSetColor(255);
	ofEnableDepthTest();
	cam.begin();
	shader.begin();
	shader.setUniform1f("u_time", ofGetElapsedTimef());
	shader.setUniform2f("u_resolution", ofGetWidth(), ofGetHeight());
	ofRotateXDeg(150);
	mesh.draw();
	shader.end();
	cam.end();
}
