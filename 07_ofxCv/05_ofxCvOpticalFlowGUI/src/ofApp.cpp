#include "ofApp.h"

using namespace ofxCv;
using namespace cv;

void ofApp::setup() {
    //init camera
    camera.initGrabber(320, 240);
    
    //GUI
    gui.setup();
    gui.add(pyrScale.setup("pyrScale", .5, 0, 1));
    gui.add(levels.setup("levels", 4, 1, 8));
    gui.add(winsize.setup("winsize", 8, 4, 64));
    gui.add(iterations.setup("iterations", 2, 1, 8));
    gui.add(polyN.setup("polyN", 7, 5, 10));
    gui.add(polySigma.setup("polySigma", 1.5, 1.1, 2));
    gui.add(OPTFLOW_FARNEBACK_GAUSSIAN.setup("OPTFLOW_FARNEBACK_GAUSSIAN", false));
    gui.add(useFarneback.setup("useFarneback", true));
    gui.add(winSize.setup("winSize", 32, 4, 64));
    gui.add(maxLevel.setup("maxLevel", 3, 0, 8));
    gui.add(maxFeatures.setup("maxFeatures", 200, 1, 1000));
    gui.add(qualityLevel.setup("qualityLevel", 0.01, 0.001, .02));
    gui.add(minDistance.setup("minDistance", 4, 1, 16));
    
    //Set to use farneback
    curFlow = &farneback;
}

void ofApp::update() {
    camera.update();
    if(camera.isFrameNew()) {
        if(useFarneback) {
            //Use farneback
            curFlow = &farneback;
            farneback.setPyramidScale(pyrScale);
            farneback.setNumLevels(levels);
            farneback.setWindowSize(winsize);
            farneback.setNumIterations(iterations);
            farneback.setPolyN(polyN);
            farneback.setPolySigma(polySigma);
            farneback.setUseGaussian(OPTFLOW_FARNEBACK_GAUSSIAN);
        } else {
            //use pyrLk
            curFlow = &pyrLk;
            pyrLk.setMaxFeatures(maxFeatures);
            pyrLk.setQualityLevel(qualityLevel);
            pyrLk.setMinDistance(minDistance);
            pyrLk.setWindowSize(winSize);
            pyrLk.setMaxLevel(maxLevel);
        }
        //Calculate optical flow
        curFlow->calcOpticalFlow(camera);
    }
}

void ofApp::draw() {
    ofBackground(0);
    
    //draw camera image
    ofSetColor(255);
    camera.draw(0,0,ofGetWidth(),ofGetHeight());

    //draw opticalflow
    ofSetColor(255, 0, 255);
    curFlow->draw(0,0,ofGetWidth(),ofGetHeight());
    
    //draw gui
    gui.draw();
}
