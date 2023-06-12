#include "ofApp.h"

using namespace ofxCv;
using namespace cv;

void ofApp::setup() {
    //init camera
    cam.initGrabber(ofGetWidth(), ofGetHeight());
    //contourFinder settings
    contourFinder.setMinAreaRadius(10);
    contourFinder.setMaxAreaRadius(200);
    background.setLearningTime(900);
	background.setThresholdValue(20);    
    //GUI
    resetBackgroundButton.addListener(this, &ofApp::resetBackgroundPressed);
    gui.setup();
    gui.add(bgThresh.setup("background thresh", 50, 0, 100));
    gui.add(contourThresh.setup("contour finder thresh", 127, 0, 255));
    gui.add(resetBackgroundButton.setup("reset background"));
}

void ofApp::update() {
    //update camera
    cam.update();
    if(cam.isFrameNew()) {
        //calculate background difference
        background.setThresholdValue(bgThresh);
        background.update(cam, thresholded);
		thresholded.update();
        //find coutors
        contourFinder.setThreshold(contourThresh);
        contourFinder.findContours(thresholded);
    }
}

void ofApp::draw() {
    //draw background difference image
    ofSetColor(255);
    thresholded.draw(0, 0);    
    //draw contours
    ofSetColor(255, 0, 0);
    contourFinder.draw();
    //draw gui
    gui.draw();
}

//reset background
void ofApp::resetBackgroundPressed(){
    background.reset();
}
