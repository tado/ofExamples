#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	float stiffness;
	float friction;
	float mass;
	glm::vec2 currentPos;
	glm::vec2 toPos;
	glm::vec2 velocity;
};
