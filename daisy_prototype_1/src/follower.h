#pragma once

#include "ofMain.h"
#include "petal.h"
#define PETALS_NUMBER 20
class follower {
    
public:
    
    void setup();
    void update();
    void draw();
    
    void petalMove();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);

    ofPoint pos;
    ofImage flowerImage;
    ofImage petalImage;
    vector <petal> myPetals;
    float radius;
    float angle;
};
