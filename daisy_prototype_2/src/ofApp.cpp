#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    flwerImage.loadImage("images/daisy1.png");
    
    myFlw.setInitialCondition(ofGetWidth()/2, ofGetHeight()/2, 0, 0);

}

//--------------------------------------------------------------
void ofApp::update(){
    myFlw.resetForce();
    myFlw.bounceOffWalls();
    myFlw.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    myFlw.draw();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    myFlw.keyPressed(key);

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
