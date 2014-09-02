#include "follower.h"

//--------------------------------------------------------------
void follower::setup(){
    
    flowerImage.loadImage("images/flower.png");
    petalImage.loadImage("images/petal0.png");

    pos.set(ofGetWidth()/2, ofGetHeight()/2);
    radius = 30;
    angle =  0;
    
    for (int i=0; i<PETALS_NUMBER; i++) {
        angle+=TWO_PI/PETALS_NUMBER;
        petal temPetal;
        myPetals.push_back(temPetal);
        float petalX = pos.x + (radius+petalImage.getWidth()/2)*cos(angle);
        float petalY = pos.y + (radius+petalImage.getWidth()/2)*sin(angle);
        myPetals.back().setup(petalImage,petalX,petalY,angle);
    }
}

//--------------------------------------------------------------
void follower::update(){
    
    for (int i=0; i<myPetals.size(); i++) {
        myPetals[i].update();
    }
    
}

//--------------------------------------------------------------
void follower::draw(){
    
    for (int i=0; i<myPetals.size(); i++) {
        myPetals[i].draw();
    }
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofSetColor(255);
    flowerImage.draw(-flowerImage.getWidth()/2, -flowerImage.getHeight()/2);
    ofPopMatrix();
    
    ofSetColor(255, 0, 220,100);
    
}

//--------------------------------------------------------------
void follower::petalMove(){
    
    for (int i=0; i<myPetals.size(); i++) {
        myPetals[i].bFixed = !myPetals[i].bFixed;
    }
}
//--------------------------------------------------------------
void follower::keyPressed(int key){
    
}

//--------------------------------------------------------------
void follower::keyReleased(int key){
    
}

//--------------------------------------------------------------
void follower::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void follower::mouseDragged(int x, int y, int follower){
    
}

//--------------------------------------------------------------
void follower::mousePressed(int x, int y, int follower){
    
}

//--------------------------------------------------------------
void follower::mouseReleased(int x, int y, int follower){
    
}

