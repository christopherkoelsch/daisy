#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup() {
    
//    ofSetLogLevel(OF_LOG_VERBOSE);
    openNIDevice.setup();
    openNIDevice.addImageGenerator();
    openNIDevice.addDepthGenerator();
    openNIDevice.setRegister(true);
    openNIDevice.setMirror(true);
    openNIDevice.addHandsGenerator();
    openNIDevice.addAllHandFocusGestures();
    openNIDevice.setMaxNumHands(4);
    for(int i = 0; i < openNIDevice.getMaxNumHands(); i++){
        ofxOpenNIDepthThreshold depthThreshold = ofxOpenNIDepthThreshold(0, 0, false, true, true, true, true);
        openNIDevice.addDepthThreshold(depthThreshold);
    }
    openNIDevice.start();
    
    //---DAISY CODE
    ofEnableAlphaBlending();
    daisyImage.loadImage("images/flowerk.png");
    petalImage.loadImage("images/petal0c.png");
    petalImageHovered.loadImage("images/loves_black2.png");
    petalImageHovered2.loadImage("images/not_black2.png");
    followerImage.loadImage("images/flower_shadow.png");
    bEmit = false;
    BGimage.loadImage("images/blue_sky.jpg");
    bDebug = false;
}

//--------------------------------------------------------------
void testApp::update(){
    
    openNIDevice.update();
    handPostion();
    
    //--daisy code-------------------------------
    
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
void testApp::draw(){
    

    //---------DAISY CODE --------
    BGimage.draw(0,0);
    
    for (int i=0; i<myFlwSmall.size(); i++) {
        myFlwSmall[i].draw();
    }
    
    for (int i=0; i<myFlws.size(); i++) {
        myFlws[i].draw();
    }
    
    //---draw kinect debug ----------
    if(bDebug){
    	ofSetColor(255, 255, 255, 255);
        openNIDevice.drawDebug();
    }
   
    for (int i = 0; i < openNIDevice.getNumTrackedHands(); i++){
        ofxOpenNIHand & hand = openNIDevice.getTrackedHand(i);
        ofPoint & handPosition = hand.getPosition();
        float posX =  ofMap(handPosition.x, 0, 640, 0, ofGetWidth());
        float posY =  ofMap(handPosition.y, 0, 480, 0, ofGetHeight());
        ofSetColor(255, 0, 0,100);
        ofCircle(posX, posY, 20);
    }
    
    ofSetColor(255);
    ofDrawBitmapString(ofToString(ofGetFrameRate()), 10,10);
}

//--------------------------------------------------------------
void testApp::handEvent(ofxOpenNIHandEvent & event){
    
//    ofLogNotice() << getHandStatusAsString(event.handStatus) << "for hand" << event.id << "from device" << event.deviceID;
}

//--------------------------------------------------------------
void testApp::exit(){
    openNIDevice.stop();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

    if (key == ' ' ) {
        bEmit = true;
    }
    
    if (key == 'd') {
        bDebug = !bDebug;
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
   

}

//--------------------------------------------------------------
void testApp::handPostion(){

    for (int i=0; i< myFlws.size(); i++) {
        handPostions.clear();
    }
    
    for (int i = 0; i < openNIDevice.getNumTrackedHands(); i++){
        ofxOpenNIHand & hand = openNIDevice.getTrackedHand(i);
        ofPoint & handPosition = hand.getPosition();
        float posX =  ofMap(handPosition.x, 0, 640, 0, ofGetWidth());
        float posY =  ofMap(handPosition.y, 0, 480, 0, ofGetHeight());
        for (int i=0; i< myFlws.size(); i++) {
            handPostions.push_back(ofPoint(posX,posY));
        }
    }
}

















