#pragma once
#include "ofMain.h"

class RandomWalker {

public:

    RandomWalker();
    void update();
    void draw();

    glm::vec2 position;
    float left, right, top, bottom;
};
