#include "ofMain.h"
#include "ofApp.h"

int main() {
    ofGLFWWindowSettings settings;
    // Set Shader version to OepnGL 2.1 (GLSL 120)
    settings.setGLVersion(2, 1);
    // Set window size to 1280x720
    settings.setSize(1280, 720);
    ofCreateWindow(settings);
    ofRunApp(new ofApp());
}
