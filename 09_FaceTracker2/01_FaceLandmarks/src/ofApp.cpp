#include "ofApp.h"

void ofApp::setup() {
    //grabber.listDevices();
    //grabber.setDeviceID(0);
    grabber.setup(1280, 720);
    tracker.setup();
}

void ofApp::update() {
    grabber.update();
    if (grabber.isFrameNew()) {
        tracker.update(grabber);
    }
}

void ofApp::draw() {
    grabber.draw(0, 0);

    vector<ofxFaceTracker2Instance> instances = tracker.getInstances();
    for (int i = 0; i < instances.size(); i++) {
        ofxFaceTracker2Landmarks landmarks = instances[i].getLandmarks();
        vector<glm::vec2> imagePoints = landmarks.getImagePoints();
        for (int j = 0; j < imagePoints.size(); j++) {
            glm::vec2 pos = imagePoints[j];
            ofSetColor(255);
            ofDrawCircle(pos, 5);
            ofSetColor(255, 0, 0);
            ofDrawBitmapString(ofToString(i * tracker.getInstances().size() + j), pos.x, pos.y);
        }
    }

    ofSetColor(255);
    ofDrawBitmapStringHighlight("Framerate : " + ofToString(ofGetFrameRate()), 10, 20);
    ofDrawBitmapStringHighlight("Tracker thread framerate : "
        + ofToString(tracker.getThreadFps()), 10, 40);
}
