#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofEnableAlphaBlending();
    daisyImage.loadImage("images/flowerk.png");
    petalImage.loadImage("images/petal0c.png");
    //petalImageHovered.loadImage("images/petal1cLovesMeNot.png");
    //petalImageHovered2.loadImage("images/petal0cLovesMe.png");
    petalImageHovered.loadImage("images/loves_black2.png");
    petalImageHovered2.loadImage("images/not_black2.png");

    //petalImageHovered.loadI`mage("images/petal01.png");
    followerImage.loadImage("images/flower_shadow.png");
    bEmit = false;
    
    BGimage.loadImage("images/blue_sky.jpg");

    //--osc
    receiver.setup(PORT);
    for(int i=0; i<4; i++){
        mouseX[i] = -10;
        mouseY[i] = -10;
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
  
    //--osc
    oscReceive();
    
    
    //--daisy
    for (int i=0; i<myFlws.size(); i++) {
        myFlws[i].resetForce();
    }
    
    for (int i=0; i<myFlws.size(); i++) {
        myFlws[i].addRepulsionForce(myFlws[i].pos.x, 0, 30, 1);
        
    }
    
    for (int i=0; i<myFlws.size(); i++) {
        myFlws[i].bounceOffWalls();
        myFlws[i].update();
    }
    
    
    for (int i=0; i<myFlwSmall.size(); i++) {
        myFlwSmall[i].resetForce();
        myFlwSmall[i].bounceOffWalls();
        myFlwSmall[i].addDampingForce();
        myFlwSmall[i].update();
    }
    
    if (bEmit) {
        float velX = -4.5;
        for (int i=0; i< 4; i++) {
           
            followerBig tempFlw;
            myFlws.push_back(tempFlw);
            myFlws.back().setInitialCondition( daisyImage, petalImage,petalImageHovered,
                                              ofGetWidth()/2, ofGetHeight()-1,
                                              0, -ofRandom(4,7));
            
            myFlws.back().setInitialCondition( daisyImage, petalImage,petalImageHovered2,
                                              ofGetWidth()/2, ofGetHeight()-1,
                                              0, -ofRandom(4,7));

        }

        for (int i=0; i<40; i++) {
            
            followerSmall tempFlw;
            myFlwSmall.push_back(tempFlw);
            myFlwSmall.back().setInitialCondition(followerImage,
                                                  ofGetWidth()/2, ofGetHeight()-1,
                                                  0, -ofRandom(3,14));
            if(i%2 == 0){
                myFlwSmall.back().bFixed = true;
            }
        }
        
        bEmit = false;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(255);
    BGimage.draw(0,0);
    
    for (int i=0; i<myFlwSmall.size(); i++) {
        myFlwSmall[i].draw();
    }
    
    for (int i=0; i<myFlws.size(); i++) {
        myFlws[i].draw();
    }
    
    //--osc
    string buf;
	buf = "FPS: "+ ofToString(ofGetFrameRate())+"\nListening for osc messages on port" + ofToString(PORT);
	ofDrawBitmapString(buf, 10, 20);
    
    for(int i=0; i<4; i++){
    	buf = "mouse: " + ofToString(mouseX[i], 4) +  " " + ofToString(mouseY[i], 4);
        ofDrawBitmapString(buf, 430, 20 + 20*i);
    }
    
    for (int i=0; i<4; i++) {
        ofSetColor(255, 0, 220,100);
        ofCircle(mouseX[i], mouseY[i], 10);
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

//--------------------------------------------------------------
void ofApp::oscReceive(){
    
    while(receiver.hasWaitingMessages()){
		// get the next message
		ofxOscMessage m;
		receiver.getNextMessage(&m);
        
		// check for mouse moved message
        
        if(m.getAddress() == "/mouse0/position"){
            // both the arguments are int32's
            mouseX[0] = m.getArgAsInt32(0);
            mouseY[0] = m.getArgAsInt32(1);
            mouseX[0] = ofMap(mouseX[0], 0, 640, 0, ofGetWidth());
            mouseY[0] = ofMap(mouseY[0], 0, 480, 0, ofGetHeight());
        } else if(m.getAddress() == "/mouse1/position"){
            // both the arguments are int32's
            mouseX[1] = m.getArgAsInt32(0);
            mouseY[1] = m.getArgAsInt32(1);
            mouseX[1] = ofMap(mouseX[1], 0, 640, 0, ofGetWidth());
            mouseY[1] = ofMap(mouseY[1], 0, 480, 0, ofGetHeight());
        } else if(m.getAddress() == "/mouse2/position"){
            // both the arguments are int32's
            mouseX[2] = m.getArgAsInt32(0);
            mouseY[2] = m.getArgAsInt32(1);
            mouseX[2] = ofMap(mouseX[2], 0, 640, 0, ofGetWidth());
            mouseY[2] = ofMap(mouseY[2], 0, 480, 0, ofGetHeight());
        } else if(m.getAddress() == "/mouse3/position"){
            // both the arguments are int32's
            mouseX[3] = m.getArgAsInt32(0);
            mouseY[3] = m.getArgAsInt32(1);
            mouseX[3] = ofMap(mouseX[3], 0, 640, 0, ofGetWidth());
            mouseY[3] = ofMap(mouseY[3], 0, 480, 0, ofGetHeight());
        }
		
    }
}
































