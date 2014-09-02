#include "startScene.h"

//--------------------------------------------------------------
void startScene::setup(){
    
    flwerImage.loadImage("images/daisy1.png");
    
    myFlw.setup();
}

//--------------------------------------------------------------
void startScene::update(){
    
    for (int i=0; i<flwers.size(); i++) {
        flwers[i].resetForce();
        float X = 0;
        float Y = 0.5;
        flwers[i].addForce(X, Y);
    }
    
    for (int i = 0; i < flwers.size(); i++){
		flwers[i].addDampingForce();
        flwers[i].bounceOffWalls();
		flwers[i].update();
	}
    
    myFlw.update();

}

//--------------------------------------------------------------
void startScene::draw(){
    
    for (int i=0; i<flwers.size(); i++) {
        flwers[i].draw();
    }
    
    myFlw.draw();
}

//--------------------------------------------------------------
void startScene::keyPressed(int key){
    
    if(key == ' '){
        myFlw.petalMove();
    }
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
    
    
//    particle temP;
//    flwers.push_back(temP);
//    flwers.back().setInitialCondition(ofGetWidth()/2, ofGetHeight()/2, 0, -30);
//    flwers.back().image = &flwerImage;
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
