#include "ofApp.h"

void ofApp::setup() {
    box2d.init();
    box2d.setFPS(30);
    box2d.createBounds();
    box2d.registerGrabbing();
}

void ofApp::update() {
    box2d.update();
}

void ofApp::draw() {
    ofSetColor(31, 127, 255);
    for (int i = 0; i < circles.size(); i++) {
        circles[i]->draw();
    }
    ofSetColor(255, 127, 31);
    for (int i = 0; i < rects.size(); i++) {
        rects[i]->draw();
    }
}

void ofApp::mouseDragged(int x, int y, int button) {
    if (button == OF_MOUSE_BUTTON_LEFT) {
        ofxBox2dCircle* c = new ofxBox2dCircle();
        float radius = ofRandom(5, 20);
        c->setPhysics(radius * 0.1, 0.5, 0.1);
        c->setup(box2d.getWorld(), x, y, radius);
        circles.push_back(ofPtr<ofxBox2dCircle>(c));
    }
    else {
        ofxBox2dRect* r = new ofxBox2dRect();
        float width = ofRandom(10, 40);
        float height = ofRandom(10, 40);
        r->setPhysics((width + height) * 0.1, 0.5, 0.1);
        r->setup(box2d.getWorld(), x, y, width, height);
        rects.push_back(ofPtr<ofxBox2dRect>(r));
    }
}
