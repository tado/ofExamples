#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	glm::vec2 currentPos;
	glm::vec2 toPos;
};
