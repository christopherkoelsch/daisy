#pragma once

#include "ofMain.h"
#include "petal.h"
#define PETALS_NUMBER 20
class follower {
    
public:
    
    ofVec2f pos;
    
    ofVec2f vel;
    ofVec2f frc;
    
    follower();
    float map(float in, float inMin,float inMax, float outMin, float outMax, float shaper);

    void setInitialCondition(ofImage &FollowerImage,ofImage &Daisy, ofImage &Petal, float px, float py, float vx, float vy, bool King);
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
    void addRepulsionForce(follower &p, float radius, float scale);
    void addAttractionForce(follower &p, float radius, float scale);
    void addDampingForce();
    void bounceOffWalls();
    
    float damping;
    float lifeTime;
    ofImage *daisyImage;
    ofImage *petalImage;
    ofImage *followerImage;
    vector <petal> myPetals;
    float radius;
    float angle;
    float angleSpeed;
    bool bPetalFixed;
    bool bIsKing;
    bool bDead;
    float scale;
    float timer;
};
