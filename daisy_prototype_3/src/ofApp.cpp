#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofEnableAlphaBlending();
    daisyImage.loadImage("images/flower.png");
    petalImage.loadImage("images/petal0.png");
    followerImage.loadImage("images/daisy1.png");
}

//--------------------------------------------------------------
void ofApp::update(){
   
    for (int i=0; i<myFlws.size(); i++) {
        myFlws[i].resetForce();
        myFlws[i].bounceOffWalls();
        myFlws[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

    for (int i=0; i<myFlws.size(); i++) {
        myFlws[i].draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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

    

    follower tempFlw;
    myFlws.push_back(tempFlw);
    myFlws.back().setInitialCondition(daisyImage, petalImage, ofGetWidth()/2, ofGetHeight(), ofRandom(-1,1), -ofRandom(-1,-2), ofRandom(0.2,0.6));
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
