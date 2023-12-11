#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();

	ofVideoGrabber cam;
	ofxCv::ContourFinder contourFinder;
	ofxPanel gui;
	ofxFloatSlider thresh;
	ofxFloatSlider minArea;
	ofxFloatSlider maxArea;
};