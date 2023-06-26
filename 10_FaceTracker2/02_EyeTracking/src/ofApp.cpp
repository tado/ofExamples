#include "ofApp.h"

void ofApp::setup() {
    //grabber.listDevices();
    //grabber.setDeviceID(0);
    grabber.setup(1280, 720);
    tracker.setup();
    ofSetCircleResolution(64);
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
        //Face size
        ofRectangle faceRect = instances[i].getBoundingBox();
        //LandMarks
        ofxFaceTracker2Landmarks landmarks = instances[i].getLandmarks();
        //Left eye
        glm::vec2 leftPos = landmarks.getImageFeature(ofxFaceTracker2Landmarks::LEFT_EYE).getCentroid2D();
        //Right eye
        glm::vec2 rightPos = landmarks.getImageFeature(ofxFaceTracker2Landmarks::RIGHT_EYE).getCentroid2D();

        //Draw face parts
        ofSetColor(255);
        ofDrawCircle(leftPos, faceRect.getWidth() / 6.0);
        ofDrawCircle(rightPos, faceRect.getWidth() / 6.0);
        ofSetColor(0);
        ofDrawCircle(leftPos, faceRect.getWidth() / 12.0);
        ofDrawCircle(rightPos, faceRect.getWidth() / 12.0);
    }

    ofSetColor(255);
    ofDrawBitmapStringHighlight("Framerate : " + ofToString(ofGetFrameRate()), 10, 20);
    ofDrawBitmapStringHighlight("Tracker thread framerate : " + ofToString(tracker.getThreadFps()), 10, 40);
}
