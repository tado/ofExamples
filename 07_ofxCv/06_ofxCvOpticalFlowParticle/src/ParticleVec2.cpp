#include "ParticleVec2.h"

ParticleVec2::ParticleVec2(){
    radius = 5.0;
    friction = 0.01;
    mass = 1.0;
    position = glm::vec2(ofGetWidth()/2.0, ofGetHeight()/2.0);
    velocity = glm::vec2(0, 0);
    minx = 0;
    miny = 0;
    maxx = ofGetWidth();
    maxy = ofGetHeight();
}

void ParticleVec2::update(){
    acceleration -= velocity * friction;
    velocity += acceleration;
    position += velocity;
    acceleration = glm::vec2(0, 0);
}

void ParticleVec2::draw(){
    ofDrawCircle(position.x, position.y, radius);
}

void ParticleVec2::addForce(glm::vec2 _force){
    acceleration += _force / mass;
}
void ParticleVec2::addForce(float forceX, float forceY){
    acceleration += glm::vec2(forceX, forceY) / mass;
}

void ParticleVec2::bounceOffWalls(){
    if (position.x > maxx){
        position.x = maxx;
        velocity.x *= -1;
    }
    if (position.x < minx){
        position.x = minx;
        velocity.x *= -1;
    }
    if (position.y > maxy){
        position.y = maxy;
        velocity.y *= -1;
    }
    if(position.y < miny){
        position.y = miny;
        velocity.y *= -1;
    }
}

void ParticleVec2::throughOffWalls(){
    if (position.x < minx) {
        position.x = maxx;
    }
    if (position.y < miny) {
        position.y = maxy;
    }
    if (position.x > maxx) {
        position.x = minx;
    }
    if (position.y > maxy) {
        position.y = miny;
    }
}

void ParticleVec2::addAttractionForce(float x, float y, float radius, float scale){
    glm::vec2 posOfForce;
    posOfForce = glm::vec2(x,y);
    glm::vec2 diff = position - posOfForce;
    float length = diff.length();
    bool bAmCloseEnough = true;
    if (radius > 0){
        if (length > radius){
            bAmCloseEnough = false;
        }
    }
    if (bAmCloseEnough == true){
        float pct = 1 - (length / radius);
        normalize(diff);
        acceleration = acceleration - diff * scale * pct;
    }
}

void ParticleVec2::addAttractionForce(ParticleVec2 &p, float radius, float scale){
    glm::vec2 posOfForce;
    posOfForce = glm::vec2(p.position.x, p.position.y);
    glm::vec2 diff = position - posOfForce;
    float length = diff.length();
    bool bAmCloseEnough = true;
    if (radius > 0){
        if (length > radius){
            bAmCloseEnough = false;
        }
    }
    if (bAmCloseEnough == true){
        float pct = 1 - (length / radius);
        normalize(diff);
        acceleration = acceleration - diff * scale * pct;
    }
}

void ParticleVec2::addRepulsionForce(float x, float y, float radius, float scale){
    glm::vec2 posOfForce;
    posOfForce = glm::vec2(x,y);
    glm::vec2 diff = position - posOfForce;
    float length = diff.length();
    bool bAmCloseEnough = true;
    if (radius > 0){
        if (length > radius){
            bAmCloseEnough = false;
        }
    }
    if (bAmCloseEnough == true){
        float pct = 1 - (length / radius);
        normalize(diff);
        acceleration = acceleration + diff * scale * pct;
    }
}

void ParticleVec2::addRepulsionForce(ParticleVec2 &p, float radius, float scale){
    glm::vec2 posOfForce;
    posOfForce = glm::vec2(p.position.x, p.position.y);
    glm::vec2 diff = position - posOfForce;
    float length = diff.length();
    bool bAmCloseEnough = true;
    if (radius > 0){
        if (length > radius){
            bAmCloseEnough = false;
        }
    }
    if (bAmCloseEnough == true){
        float pct = 1 - (length / radius);
        normalize(diff);
        acceleration = acceleration + diff * scale * pct;
    }
}
