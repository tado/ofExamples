#include "ofMain.h"
#include "ofApp.h"

int main() {
    ofGLFWWindowSettings settings;
    // Set Shader version to OepnGL 4.3 (GLSL 430)
    settings.setGLVersion(4, 3);
    // Set window size to 1280x720
    settings.setSize(1280, 720);
    ofCreateWindow(settings);
    ofRunApp(new ofApp());
}