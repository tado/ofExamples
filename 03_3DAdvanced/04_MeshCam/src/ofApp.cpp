#include "ofApp.h"

void ofApp::setup() {
    ofBackground(0);
    ofEnableDepthTest();
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    cam.setDistance(400);
    meshWidth = 640;
    meshHeight = 480;
    num_particles = meshWidth * meshHeight;
    myVideo.initGrabber(640, 480);
    mesh.setMode(OF_PRIMITIVE_POINTS);
}

void ofApp::update() {
    myVideo.update();
    if (myVideo.isFrameNew()) {
        mesh.clear();
        ofPixels pixels = myVideo.getPixels();
        for (int i = 0; i < meshWidth; i++) {
            for (int j = 0; j < meshHeight; j++) {
                float r = (float)pixels[j * int(myVideo.getWidth()) * 3 + i * 3] / 255.0;
                float g = (float)pixels[j * int(myVideo.getWidth()) * 3 + i * 3 + 1] / 255.0;
                float b = (float)pixels[j * int(myVideo.getWidth()) * 3 + i * 3 + 2] / 255.0;
                float brightness = (r + g + b) / 3.0f;
                glm::vec3 vert = glm::vec3(i - meshWidth / 2, j - meshHeight / 2, brightness * 255.0);
                mesh.addVertex(vert);
                ofFloatColor color = ofFloatColor(r, g, b, 0.8);
                mesh.addColor(color);
            }
        }
    }
}

void ofApp::draw() {
    cam.begin();
    ofScale(1, -1, 1);
    glPointSize(3);
    mesh.draw();
    cam.end();

    string info;
    info = "Vertex num = " + ofToString(num_particles, 0) + "\n";
    info += "FPS = " + ofToString(ofGetFrameRate(), 2);
    ofDrawBitmapString(info, 30, 30);
}

void ofApp::keyPressed(int key) {
    if (key == 'f') {
        ofToggleFullscreen();
    }
}