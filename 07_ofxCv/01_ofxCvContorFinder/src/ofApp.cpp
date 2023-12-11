#include "ofApp.h"

using namespace ofxCv;
using namespace cv;

void ofApp::setup() {
    cam.initGrabber(ofGetWidth(), ofGetHeight());
    contourFinder.setMinAreaRadius(50);
    contourFinder.setMaxAreaRadius(200);
}

void ofApp::update() {
    cam.update();
    if (cam.isFrameNew()) {
        float thresh = ofMap(mouseX, 0, ofGetWidth(), 0, 255);
        contourFinder.setThreshold(thresh);
        contourFinder.findContours(cam);
    }
}

void ofApp::draw() {
    ofSetColor(255);
    cam.draw(0, 0);
    contourFinder.draw();
    for (int i = 0; i < contourFinder.size(); i++) {
        cv::Point2f center = contourFinder.getCenter(i);
        ofSetColor(255, 0, 0);
        ofDrawCircle(center.x, center.y, 5);
    }
}