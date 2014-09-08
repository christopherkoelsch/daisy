#include "follower.h"


follower::follower(){
    
	damping = 0.001f;
    radius = 30;
    angle =  0;
    bPetalFixed = true;
}

//--------------------------------------------------------------
void follower::setInitialCondition(float px, float py, float vx, float vy){
    
    pos.set(px,py);
	vel.set(vx,vy);
    flowerImage.loadImage("images/flower.png");
    petalImage.loadImage("images/petal0.png");
    
    for (int i=0; i<PETALS_NUMBER-5; i++) {
        float ang = angle+TWO_PI/PETALS_NUMBER*i;
        petal temPetal;
        myPetals.push_back(temPetal);
        float petalX = pos.x + (radius+petalImage.getWidth()/2)*cos(ang);
        float petalY = pos.y + (radius+petalImage.getWidth()/2)*sin(ang);
        myPetals.back().setup(petalImage,petalX,petalY,ang);
    }
}
//--------------------------------------------------------------
void follower::update(){
    
    vel = vel + frc;
	pos = pos + vel;
    
    angle-=0.01;
    
    for (int i=0; i<myPetals.size(); i++) {
        
        if (!myPetals[i].bFly) {
            for (int i=0; i<PETALS_NUMBER; i++) {
                float ang = angle+TWO_PI/PETALS_NUMBER*i;
                float x = pos.x + (radius+petalImage.getWidth()/2)*cos(ang);
                float y = pos.y + (radius+petalImage.getWidth()/2)*sin(ang);
                myPetals[i].pos.set(x,y);
                myPetals[i].resetAngle(ang);
            }
            
        }else{
            
            myPetals[i].resetForce();
            myPetals[i].addRepulsionForce(myPetals[i].repulsionPos.x,
                                          myPetals[i].repulsionPos.y,
                                          myPetals[i].repulsionRadius,
                                          myPetals[i].repulsionScale);
            
            myPetals[i].addForce(myPetals[i].gravity.x, myPetals[i].gravity.y);
            myPetals[i].addDampingForce();
            myPetals[i].update();
            
        }
    }
    
    
    
    
}

//--------------------------------------------------------------
void follower::draw(){
    
    for (int i=0; i<myPetals.size(); i++) {
        myPetals[i].draw();
    }
    
    ofPushMatrix();
    ofTranslate(pos);
    ofRotateZ(angle*RAD_TO_DEG);
    ofSetColor(255);
    flowerImage.draw(-flowerImage.getWidth()/2, -flowerImage.getHeight()/2);
    ofPopMatrix();
    

    
    
}

//--------------------------------------------------------------
void follower::petalMove(){
    
    
    
    
    
    
}
//--------------------------------------------------------------
void follower::keyPressed(int key){
    
}
//--------------------------------------------------------------
void follower::keyReleased(int key){
    
    
}

//--------------------------------------------------------------
void follower::mouseMoved(int x, int y ){
    
    ofPoint mouse(x,y);
    float dis = mouse.distance(pos);
    if (dis<136 && bPetalFixed) {
        for (int i=0; i<myPetals.size(); i++) {
            
            ofPoint offset = ofPoint(ofRandom(-50,50),ofRandom(-50,50));
            myPetals[i].repulsionPos = pos + offset;
            myPetals[i].repulsionRadius = myPetals[i].repulsionPos.distance(myPetals[i].pos)*ofRandom(1.1,1.2);
            myPetals[i].repulsionScale = ofRandom(0.3,3);
            myPetals[i].rotateSpeed = ofRandom(5,8);
            myPetals[i].gravity.set(0, 0.002);
            myPetals[i].bFly = true;
        }
        
        bPetalFixed = false;
    }
}

//--------------------------------------------------------------
void follower::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void follower::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void follower::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void follower::resetForce(){
    
    frc.set(0,0);
}
//--------------------------------------------------------------
void follower::addForce(float x, float y){
    
    frc.x = frc.x + x;
    frc.y = frc.y + y;
    
}
//--------------------------------------------------------------
void follower::addRepulsionForce(float x, float y, float radius, float scale){
    
    ofVec2f posOfForce;
	posOfForce.set(x,y);
	
	// ----------- (2) calculate the difference & length
	
	ofVec2f diff	= pos - posOfForce;
	float length	= diff.length();
	
	// ----------- (3) check close enough
	
	bool bAmCloseEnough = true;
    if (radius > 0){
        if (length > radius){
            bAmCloseEnough = false;
        }
    }
	// ----------- (4) if so, update force
    
	if (bAmCloseEnough == true){
		float pct = 1 - (length / radius);  // stronger on the inside
        diff.normalize();
		frc.x = frc.x + diff.x * scale * pct;
        frc.y = frc.y + diff.y * scale * pct;
    }
    
}
//--------------------------------------------------------------
void follower::addAttractionForce(float x, float y, float radius, float scale){
    
    // ----------- (1) make a vector of where this position is:
	
	ofVec2f posOfForce;
	posOfForce.set(x,y);
	
	// ----------- (2) calculate the difference & length
	
	ofVec2f diff	= pos - posOfForce;
	float length	= diff.length();
	
	// ----------- (3) check close enough
	
	bool bAmCloseEnough = true;
    if (radius > 0){
        if (length > radius){
            bAmCloseEnough = false;
        }
    }
	
	// ----------- (4) if so, update force
    
	if (bAmCloseEnough == true){
		float pct = 1 - (length / radius);  // stronger on the inside
		diff.normalize();
		frc.x = frc.x - diff.x * scale * pct;
        frc.y = frc.y - diff.y * scale * pct;
    }
}
//--------------------------------------------------------------
void follower::addRepulsionForce(follower &p, float radius, float scale){
    
    // ----------- (1) make a vector of where this particle p is:
	ofVec2f posOfForce;
	posOfForce.set(p.pos.x,p.pos.y);
	
	// ----------- (2) calculate the difference & length
	
	ofVec2f diff	= pos - posOfForce;
	float length	= diff.length();
	
	// ----------- (3) check close enough
	
	bool bAmCloseEnough = true;
    if (radius > 0){
        if (length > radius){
            bAmCloseEnough = false;
        }
    }
	
	// ----------- (4) if so, update force
    
	if (bAmCloseEnough == true){
		float pct = 1 - (length / radius);  // stronger on the inside
		diff.normalize();
        frc.x = frc.x + diff.x * scale * pct;
        frc.y = frc.y + diff.y * scale * pct;
        p.frc.x = p.frc.x - diff.x * scale * pct;
        p.frc.y = p.frc.y - diff.y * scale * pct;
    }
    
}
//--------------------------------------------------------------
void follower::addAttractionForce(follower &p, float radius, float scale){
    
    // ----------- (1) make a vector of where this particle p is:
	ofVec2f posOfForce;
	posOfForce.set(p.pos.x,p.pos.y);
	
	// ----------- (2) calculate the difference & length
	
	ofVec2f diff	= pos - posOfForce;
	float length	= diff.length();
	
	// ----------- (3) check close enough
	
	bool bAmCloseEnough = true;
    if (radius > 0){
        if (length > radius){
            bAmCloseEnough = false;
        }
    }
	
	// ----------- (4) if so, update force
    
	if (bAmCloseEnough == true){
		float pct = 1 - (length / radius);  // stronger on the inside
		diff.normalize();
		frc.x = frc.x - diff.x * scale * pct;
        frc.y = frc.y - diff.y * scale * pct;
		p.frc.x = p.frc.x + diff.x * scale * pct;
        p.frc.y = p.frc.y + diff.y * scale * pct;
    }
    
}
//--------------------------------------------------------------
void follower::addDampingForce(){
    
    frc.x = frc.x - vel.x * damping;
    frc.y = frc.y - vel.y * damping;
}

//--------------------------------------------------------------
void follower::bounceOffWalls(){
    
    // sometimes it makes sense to damped, when we hit
	bool bDampedOnCollision = true;
	bool bDidICollide = false;
	
	// what are the walls
	float minx = 0;
	float miny = 0;
	float maxx = ofGetWidth();
	float maxy = ofGetHeight();
	
	if (pos.x > maxx){
		pos.x = maxx; // move to the edge, (important!)
		vel.x *= -1;
		bDidICollide = true;
	} else if (pos.x < minx){
		pos.x = minx; // move to the edge, (important!)
		vel.x *= -1;
		bDidICollide = true;
	}
	
	if (pos.y > maxy){
		pos.y = maxy; // move to the edge, (important!)
		vel.y *= -1;
		bDidICollide = true;
	} else if (pos.y < miny){
		pos.y = miny; // move to the edge, (important!)
		vel.y *= -1;
		bDidICollide = true;
	}
	
    //	if (bDidICollide == true && bDampedOnCollision == true){
    //		vel *= 0.3;
    //	}
}







