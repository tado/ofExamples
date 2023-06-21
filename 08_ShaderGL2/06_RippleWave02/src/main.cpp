#include "ofMain.h"
#include "ofApp.h"

int main() {
    ofGLFWWindowSettings settings;
    // Set version to OepnGL 2.1 (GLSL 120)
    settings.setGLVersion(2, 1);
    
    settings.setSize(1280, 720);
    ofCreateWindow(settings);
    ofRunApp(new ofApp());
}
