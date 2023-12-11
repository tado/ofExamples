#include "ofApp.h"

using namespace ofxCv;
using namespace cv;

void ofApp::setup() {
    // setup camera
    cam.initGrabber(ofGetWidth(), ofGetHeight());
    // setup GUI
    gui.setup();
    gui.add(thresh.setup("Threshold", 128, 0, 255));
    gui.add(minArea.setup("Min Area", 10, 1, 100));
    gui.add(maxArea.setup("Max Area", 200, 1, 500));
}

void ofApp::update() {
    cam.update();
    if (cam.isFrameNew()) {
        // find contours
        contourFinder.setMinAreaRadius(minArea);
        contourFinder.setMaxAreaRadius(maxArea);
        contourFinder.setThreshold(thresh);
        contourFinder.findContours(cam);
    }
}

void ofApp::draw() {
    ofSetColor(255);
    cam.draw(0, 0);
    // draw contours
    contourFinder.draw();
    // draw centers
    for (int i = 0; i < contourFinder.size(); i++) {
        cv::Point2f center = contourFinder.getCenter(i);
        ofSetColor(255, 0, 0);
        ofDrawCircle(center.x, center.y, 10);
    }
    // draw GUI
    gui.draw();
}