#include "ofApp.h"

using namespace ofxCv;
using namespace cv;

void ofApp::setup() {
    ofSetVerticalSync(true);
    ofSetFrameRate(120);
    cam.initGrabber(320, 240);
    
    mesh.setMode(OF_PRIMITIVE_TRIANGLES);
    stepSize = 8;
    ySteps = cam.getHeight() / stepSize;
    xSteps = cam.getWidth() / stepSize;
    for(int y = 0; y < ySteps; y++) {
        for(int x = 0; x < xSteps; x++) {
            mesh.addVertex(glm::vec3(x * stepSize, y * stepSize, 0));
            mesh.addTexCoord(glm::vec3(x * stepSize, y * stepSize, 0));
        }
    }
    for(int y = 0; y + 1 < ySteps; y++) {
        for(int x = 0; x + 1 < xSteps; x++) {
            int nw = y * xSteps + x;
            int ne = nw + 1;
            int sw = nw + xSteps;
            int se = sw + 1;
            mesh.addIndex(nw);
            mesh.addIndex(ne);
            mesh.addIndex(se);
            mesh.addIndex(nw);
            mesh.addIndex(se);
            mesh.addIndex(sw);
        }
    }
}

void ofApp::update() {
    cam.update();
    if(cam.isFrameNew()) {
        flow.setWindowSize(8);
        flow.calcOpticalFlow(cam);
        int i = 0;
        float distortionStrength = 4;
        for(int y = 1; y + 1 < ySteps; y++) {
            for(int x = 1; x + 1 < xSteps; x++) {
                int i = y * xSteps + x;
                glm::vec3 position(x * stepSize, y * stepSize, 0);
                ofRectangle area(position - glm::vec2(stepSize, stepSize) / 2, stepSize, stepSize);
                glm::vec2 offset = flow.getAverageFlowInRegion(area);
                mesh.setVertex(i, position + distortionStrength * offset);
                i++;
            }
        }
    }
}

void ofApp::draw() {
    ofBackground(0);
    float scale = ofGetWidth() / 320.0;
    ofScale(scale, scale);
    cam.getTexture().bind();
    mesh.draw();
    cam.getTexture().unbind();
    if(ofGetMousePressed()) {
        mesh.drawWireframe();
    }
}
