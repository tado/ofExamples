#pragma once
#include "ofMain.h"

class ParticleVec2 {
    
public:
    ParticleVec2();
    void update();
    void draw();
    void addForce(glm::vec2 force);
    void addForce(float forceX, float forceY);
    void bounceOffWalls();
    void throughOffWalls();
    
    void addAttractionForce(float x, float y, float radius, float scale);
    void addAttractionForce(ParticleVec2 &p, float radius, float scale);
    void addRepulsionForce(float x, float y, float radius, float scale);
    void addRepulsionForce(ParticleVec2 &p, float radius, float scale);
        
    glm::vec2 position;
    glm::vec2 velocity;
    glm::vec2 acceleration;
    float friction;
    float radius;
    float mass;
    float maxx, maxy, minx, miny;
};
