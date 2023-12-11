#include "ofApp.h"

using namespace ofxCv;
using namespace cv;

void ofApp::setup() {
    //init draw settings
    mesh.setMode(OF_PRIMITIVE_POINTS);
    glPointSize(5.0);

    //init camera
    camera.initGrabber(320, 180);

    //GUI
    resetParticleButton.addListener(this, &ofApp::resetParticlePressed);
    gui.setup();
    gui.add(pyrScale.setup("pyrScale", .5, 0, 1));
    gui.add(levels.setup("levels", 4, 1, 8));
    gui.add(winsize.setup("winsize", 8, 4, 64));
    gui.add(iterations.setup("iterations", 2, 1, 8));
    gui.add(polyN.setup("polyN", 7, 5, 10));
    gui.add(polySigma.setup("polySigma", 1.5, 1.1, 2));
    gui.add(flowScale.setup("flowScale", 0.5, 0.0, 1.0));
    gui.add(drawFlow.setup("draw opticalflow", true));
    gui.add(fullscreen.setup("fullscreen", false));
    gui.add(resetParticleButton.setup("reset particles"));

    //init particles
    for (int i = 0; i < NUM; i++) {
        ParticleVec2 myParticle;
        myParticle.friction = 0.01;
        myParticle.position = glm::vec2(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
        particles.push_back(myParticle);
    }
}

void ofApp::update() {
    camera.update();
    if (camera.isFrameNew()) {
        flow.setPyramidScale(pyrScale);
        flow.setNumLevels(levels);
        flow.setWindowSize(winsize);
        flow.setNumIterations(iterations);
        flow.setPolyN(polyN);
        flow.setPolySigma(polySigma);

        //calculate opticalflow
        flow.calcOpticalFlow(camera);
    }

    mesh.clear();
    for (int i = 0; i < particles.size(); i++) {
        //calculate force from opticalflow to the particle
        glm::vec2 force = glm::vec2(0, 0);
        glm::vec2 pos;
        pos.x = particles[i].position.x * float(camera.getWidth()) / float(ofGetWidth());
        pos.y = particles[i].position.y * float(camera.getHeight()) / float(ofGetHeight());
                
        if (pos.x > 0 && pos.y > 0 && pos.x < camera.getWidth() && pos.y < camera.getHeight()) {
            force = flow.getFlowOffset(pos.x, pos.y) * glm::vec1(flowScale);
        }
        
        //add VBO mesh vertex
        mesh.addVertex(glm::vec3(particles[i].position.x, particles[i].position.y, 0));
        mesh.addColor(ofFloatColor(0.0, 0.0, 1.0));

        //update particles
        particles[i].addForce(glm::vec2(force.x, force.y));
        particles[i].update();
        particles[i].throughOffWalls();
    }
}

void ofApp::draw() {
    ofSetFullscreen(fullscreen);
    ofBackground(0);
    ofSetColor(255);

    //draw camera image
    camera.draw(0, 0, ofGetWidth(), ofGetHeight());

    //draw optical flow
    if (drawFlow) {
        ofSetColor(255, 0, 255);
        flow.draw(0, 0, ofGetWidth(), ofGetHeight());
    }

    //draw particles mesh
    mesh.draw();

    //draw gui
    gui.draw();
}

void ofApp::resetParticlePressed() {
    particles.clear();
    for (int i = 0; i < NUM; i++) {
        ParticleVec2 myParticle;
        myParticle.friction = 0.01;
        myParticle.radius = 2;
        myParticle.position = glm::vec2(ofGetWidth()), ofRandom(ofGetHeight());
        particles.push_back(myParticle);
    }
}
