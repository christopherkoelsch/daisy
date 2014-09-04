#include "petal.h"


petal::petal(){
    setInitialCondition(0,0,0,0);
	damping = 0.005f;
    gravity.set(0,0);
    rotateSpeed = 0;
    diff = ofRandom(-0.2, 0.2);
    bFly = false;
}

//--------------------------------------------------------------
void petal::setup(ofImage &IMAGE, float x, float y, float Angle){
    
    image = &IMAGE;
    setInitialCondition(x, y, 0, 0);
    angle =  Angle*RAD_TO_DEG;
    offset = ofRandom(1000);
}

//--------------------------------------------------------------
void petal::update(){

    vel = vel + frc;
	pos = pos + vel;
    angle +=  rotateSpeed * vel.length() * diff;
    

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
//--------------------------------------------------------------
void petal::resetForce(){
    
    frc.set(0,0);
}
//--------------------------------------------------------------
void petal::addForce(float x, float y){
    
    frc.x = frc.x + x;
    frc.y = frc.y + y;
}
//--------------------------------------------------------------
void petal::addDampingForce(){
  
    frc.x = frc.x - vel.x * damping;
    frc.y = frc.y - vel.y * damping;
    
}
//--------------------------------------------------------------
void petal::setInitialCondition(float px, float py, float vx, float vy){

    pos.set(px,py);
	vel.set(vx,vy);
}
//--------------------------------------------------------------
void petal::addRepulsionForce(float x, float y, float radius, float scale){
	
	ofVec2f posOfForce;
	posOfForce.set(x,y);
		
	ofVec2f diff	= pos - posOfForce;
	float length	= diff.length();
		
	bool bAmCloseEnough = true;
    if (radius > 0){
        if (length > radius){
            bAmCloseEnough = false;
        }
    }
    
	if (bAmCloseEnough == true){
		float pct = 1 - (length / radius);  // stronger on the inside
        diff.normalize();
		frc.x = frc.x + diff.x * scale * pct;
        frc.y = frc.y + diff.y * scale * pct;
    }
    
    
}


























