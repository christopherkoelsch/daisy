#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofEnableAlphaBlending();
    daisyImage.loadImage("images/flower.png");
    petalImage.loadImage("images/petal0.png");
    followerImage.loadImage("images/daisy1.png");
    bEmit = false;
}

//--------------------------------------------------------------
void ofApp::update(){
   
    for (int i=0; i<myFlws.size(); i++) {
        myFlws[i].resetForce();
        myFlws[i].bounceOffWalls();
        myFlws[i].update();
    }
    
    
    if (bEmit) {
        for (int i=0; i< 40 ; i++) {
            
            int min = -15;
            int max = -60;
            bool bKing = false;
            if (i%10 == 0) {
                bKing = true;
                max = -1;
                max = -4;
            }
            follower tempFlw;
            myFlws.push_back(tempFlw);
            myFlws.back().setInitialCondition(followerImage,daisyImage, petalImage, ofGetWidth()/2, ofGetHeight()+200, ofRandom(-1,1), -ofRandom(min,max), bKing);
            
            cout<<i%10<<endl;
        }
        
        bEmit = false;
        
        
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

    if (key == ' ' ) {
        bEmit = true;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){


    for (int i=0; i<myFlws.size(); i++) {
        myFlws[i].mouseMoved(x, y);
    }
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
