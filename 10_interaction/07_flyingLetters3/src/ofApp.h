#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	vector <glm::vec2> mousePos;
	int delayLength;
	int skip;
};
