#pragma once

#include "ofMain.h"
#include "baseScene.h"
#include "particle.h"
#include "follower.h"

class startScene : public baseScene {

public:
    
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    vector<particle> flwers;
    ofImage flwerImage;
    follower myFlw;
};

