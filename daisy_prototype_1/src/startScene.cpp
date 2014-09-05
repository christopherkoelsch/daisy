#include "startScene.h"

//--------------------------------------------------------------
void startScene::setup(){
    
    flwerImage.loadImage("images/daisy1.png");
    
    myFlw.setInitialCondition(ofGetWidth()/2, ofGetHeight()/2, ofRandom(-1,1), ofRandom(-1,1));
}

//--------------------------------------------------------------
void startScene::update(){
    
    myFlw.resetForce();
    myFlw.bounceOffWalls();
    myFlw.update();

}

//--------------------------------------------------------------
void startScene::draw(){
    
    myFlw.draw();
}

//--------------------------------------------------------------
void startScene::keyPressed(int key){
    
    myFlw.keyPressed(key);
    
}

//--------------------------------------------------------------
void startScene::keyReleased(int key){
    
}

//--------------------------------------------------------------
void startScene::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void startScene::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void startScene::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void startScene::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void startScene::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void startScene::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void startScene::dragEvent(ofDragInfo dragInfo){
    
}
