#pragma once

#include "ofMain.h"
#include "petal.h"
#define PETALS_NUMBER 20
class followerBig {
    
public:
    
    ofVec2f pos;
    
    ofVec2f vel;
    ofVec2f frc;
    
    followerBig();
    float map(float in, float inMin,float inMax, float outMin, float outMax, float shaper);

    void setInitialCondition(ofImage &Daisy, ofImage &Petal, float px, float py, float vx, float vy);
    void update();
    void draw();
    
    void petalMove();
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    
    void resetForce();
    void addForce(float x, float y);
    void addRepulsionForce(float x, float y, float radius, float scale);
    void addAttractionForce(float x, float y, float radius, float scale);
    void addRepulsionForce(followerBig &p, float radius, float scale);
    void addAttractionForce(followerBig &p, float radius, float scale);
    void addDampingForce();
    void bounceOffWalls();
    
    float damping;
    ofImage *daisyImage;
    ofImage *petalImage;
    vector <petal> myPetals;
    float radius;
    float angle;
    float angleSpeed;
    bool bPetalFixed;
};
