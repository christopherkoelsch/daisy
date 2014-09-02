#include "petal.h"

//--------------------------------------------------------------
void petal::setup(ofImage &IMAGE, float x, float y, float Angle){
    
    image = &IMAGE;
    pos.set(x, y);
    angle =  Angle*RAD_TO_DEG;
    bFixed = true;
    offset = ofRandom(1000);
}

//--------------------------------------------------------------
void petal::update(){
    
    if (bFixed == false) {
        angle+=10;
        pos.x = ofNoise(ofGetElapsedTimef()+offset*0.01)*ofGetWidth();
        pos.y = ofNoise(ofGetElapsedTimef()+1000+offset*0.01)*ofGetHeight();
    }
}

//--------------------------------------------------------------
void petal::draw(){
    
   
        ofPushMatrix();
        ofTranslate(pos.x,pos.y);
        ofRotateZ(angle);
        ofSetColor(255);
        image->draw( -image->getWidth()/2, -image->getHeight()/2);
        ofPopMatrix();
    
    
    
}

//--------------------------------------------------------------
void petal::keyPressed(int key){
    
}

//--------------------------------------------------------------
void petal::keyReleased(int key){
    
}

//--------------------------------------------------------------
void petal::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void petal::mouseDragged(int x, int y, int petal){
    
}

//--------------------------------------------------------------
void petal::mousePressed(int x, int y, int petal){
    
}

//--------------------------------------------------------------
void petal::mouseReleased(int x, int y, int petal){
    
}

