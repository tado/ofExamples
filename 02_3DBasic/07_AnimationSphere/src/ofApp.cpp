#include "ofApp.h"

void ofApp::setup() {
    ofEnableDepthTest();

    light.enable();
    light.setPosition(-100, 100, 2000);

    material.setAmbientColor(ofColor(31, 63, 127));
    material.setDiffuseColor(ofColor(0, 127, 255));
    material.setSpecularColor(ofColor(255, 255, 0, 255));
    material.setShininess(80);
    
    cam.setDistance(400);
}

void ofApp::update() {
    location.push_back(glm::vec3(0, 0, 0));
    velocity.push_back(glm::vec3(ofRandom(-4, 4), ofRandom(-4, 4), ofRandom(-4, 4)));
    ofSpherePrimitive sp;
    sp.set(ofRandom(20, 80), 12);
    sphere.push_back(sp);
    if (location.size() > 50) {
        location.erase(location.begin());
        velocity.erase(velocity.begin());
        sphere.erase(sphere.begin());
    }
    for (int i = 0; i < location.size(); i++) {
        location[i] += velocity[i];
        sphere[i].setRadius(sphere[i].getRadius() * 0.95);
    }
}

void ofApp::draw() {
    cam.begin();
    material.begin();
    for (int i = 0; i < location.size(); i++) {
        sphere[i].setPosition(location[i]);
        sphere[i].draw();
    }
    material.end();
    cam.end();
    ofSetColor(255);
    ofDrawBitmapString(location.size(), 10, 20);
    ofDrawBitmapString(ofGetFrameRate(), 10, 40);
}