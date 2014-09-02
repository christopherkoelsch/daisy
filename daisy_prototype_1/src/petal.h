#pragma once

#include "ofMain.h"

class petal {
    
public:
    
    void setup(ofImage &IMAGE, float x, float y, float Angle);
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);

    ofImage *image;
    ofPoint pos;
    float angle;
    float offset;
    bool bFixed;
};
