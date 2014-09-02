#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	
    ofBackground(173,255, 249);
    
    spot.loadImage("daisy1.png");
    
    ard.connect("/dev/tty.usbmodem1411", 57600);
    
    ofAddListener(ard.EInitialized, this, &testApp::setupArduino);
    
    
    
	bSetupArduino	= false;
    ardButtonPressed = false;
    ard.sendDigitalPinMode(13, ARD_OUTPUT);
    
//    
//	for (int i = 0; i < 1; i++){
//		particle myParticle;
//		myParticle.setInitialCondition(100,100,ofRandom(-10,10), ofRandom(-10,10));
//        myParticle.img = &spot;
//		// more interesting with diversity :)
//		myParticle.damping = ofRandom(0.001, 0.05);
//		particles.push_back(myParticle);
//	}
}

//--------------------------------------------------------------
void testApp::update(){
    
//    updateArduino();
	// on every frame
	// we reset the forces
	// add in any forces on the particle
	// perfom damping and
	// then update
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].resetForce();
		particles[i].addForce(0, -1.5);
		particles[i].addDampingForce();
//		particles[i].bounceOffWalls();
		particles[i].update();
	}
    
//    if(ardButtonPressed){
//        for (int i = 0; i < particles.size(); i++){
//            particles[i].setInitialCondition(mouseX,mouseY,ofRandom(-10,10), ofRandom(-10,10));
//            
//        }
//
//        if(mouse_pressed){
//         for (int i = 0; i < particles.size(); i++){
//         particles[i].setInitialCondition(mouseX,mouseY,ofRandom(-10,10), ofRandom(-10,10));
//         
//         }
    
        
        
        
        
//    }
//    int buttonState = ard.getDigital(2);
    
}

//--------------------------------------------------------------
//--------------------------------------------------------------
void testApp::setupArduino(const int & version) {
	
	// remove listener because we don't need it anymore
	ofRemoveListener(ard.EInitialized, this, &testApp::setupArduino);
	ard.sendDigitalPinMode(2, ARD_INPUT);
    //ard.sendDigitalPinMode(13, ARD_OUTPUT);
    // ard.sendDigital(13,ARD_LOW);
	bSetupArduino = true;
    
    
    
}

//--------------------------------------------------------------
void testApp::updateArduino(){
    
	 //update the arduino, get any data or messages.
  	 ard.update();
    
    
}
//--------------------------------------------------------------


void testApp::draw(){
    
    ofEnableAlphaBlending();
    
    
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].draw();
	}
    
//    ofSetColor(40,40,0);
//	
//	ofSetColor(255,255,255);
	//ofDrawBitmapString(reportString, 30, 30);
    
    
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){
//    switch (key) {
//        case OF_KEY_UP:
//            ard.sendDigital(13, ARD_HIGH);  // turn LED on
//            break;
//        case OF_KEY_DOWN:
//            ard.sendDigital(13, ARD_LOW); // turn LED off
//            break;
//        default:
//            break;
//    }
}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
//    ard.sendDigital(13, ARD_HIGH);
//    mouse_pressed = true;
    
//    for (int i = 0; i < particles.size(); i++){
//                particles[i].setInitialCondition(mouseX,mouseY,ofRandom(-10,10), ofRandom(-10,10));
//        
//
//                }
    
   
	for (int i = 0; i < 10; i++){
		particle myParticle;
		myParticle.setInitialCondition(384,560,0,-.05);
//        particles[i].setInitialCondition(mouseX,mouseY,ofRandom(-10,10), ofRandom(-10,10));

        myParticle.img = &spot;
		myParticle.damping = ofRandom(0.1, 0.05);
		particles.push_back(myParticle);
	}

}

//--------------------------------------------------------------
void testApp::mouseReleased(){
//    ard.sendDigital(13, ARD_LOW);
    
}
