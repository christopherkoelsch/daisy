#include "follower.h"

float follower::map(float in, float inMin,float inMax, float outMin, float outMax, float shaper){
    float pct = ofMap (in, inMin, inMax, 0, 1, true);
    pct = powf(pct, shaper);
    float out = ofMap(pct, 0,1, outMin, outMax, true);
    return out;
}

//--------------------------------------------------------------
follower::follower(){
    
	damping = 0.001f;
    radius = 30;
    angle =  0;
    bPetalFixed = true;
    bDead = false;
    timer = ofGetElapsedTimeMillis();
    angleSpeed = ofRandom(-0.02,0.02);
    lifeTime = ofRandom(15000,25000);
}

//--------------------------------------------------------------
void follower::setInitialCondition(ofImage &FollowerImage, ofImage &Daisy, ofImage &Petal, float px, float py, float vx, float vy, bool King){
    
    followerImage = &FollowerImage;
    daisyImage = &Daisy;
    petalImage = &Petal;
    pos.set(px,py);
	vel.set(vx,vy);
    bIsKing = King;
    
    if (bIsKing) {
        scale = 1;
        for (int i=0; i<PETALS_NUMBER; i++) {
            float ang = angle+TWO_PI/PETALS_NUMBER*i;
            petal temPetal;
            myPetals.push_back(temPetal);
            float petalX = pos.x + (radius+petalImage->getWidth()/2)*scale*cos(ang);
            float petalY = pos.y + (radius+petalImage->getWidth()/2)*scale*sin(ang);
            myPetals.back().setup(Petal,petalX,petalY,ang, scale);
        }
    }else{
        scale = ofRandom(0.15,0.6);
    }
    
    
}
//--------------------------------------------------------------
void follower::update(){
    
    vel = vel + frc;
	pos = pos + vel;
    
    angle+=angleSpeed;
    
    if (bIsKing){
        for (int i=0; i<myPetals.size(); i++) {
            
            if (!myPetals[i].bFly) {
                float ang = angle+TWO_PI/PETALS_NUMBER*i;
                float x = pos.x + (radius+petalImage->getWidth()/2)*scale*cos(ang);
                float y = pos.y + (radius+petalImage->getWidth()/2)*scale*sin(ang);
                myPetals[i].pos.set(x,y);
                myPetals[i].resetAngle(ang);
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

    }else{
    
        if(ofGetElapsedTimeMillis() - timer > lifeTime){
            bDead = true;
        }
    }
    
    
    
    
}

//--------------------------------------------------------------
void follower::draw(){
    
    if (bIsKing) {
        for (int i=0; i<myPetals.size(); i++) {
            myPetals[i].draw();
        }
        
        ofPushMatrix();
        ofTranslate(pos);
        ofScale(scale,scale);
        ofRotateZ(angle*RAD_TO_DEG);
        ofSetColor(255);
        daisyImage->draw(-daisyImage->getWidth()/2, -daisyImage->getHeight()/2);
        ofPopMatrix();

    }else{
    
        if (!bDead) {
            ofPushMatrix();
            ofTranslate(pos);
            ofScale(scale,scale);
            ofRotateZ(angle*RAD_TO_DEG);
            ofSetColor(255, map(ofGetElapsedTimeMillis() - timer, 0, lifeTime, 255,0, 3.5));
            followerImage->draw(-followerImage->getWidth()/2, -followerImage->getHeight()/2);
            ofPopMatrix();
        }
    }
    

    
    
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
    
    if (bIsKing) {
        ofPoint mouse(x,y);
        float dis = mouse.distance(pos);
        if (dis<136 && bPetalFixed) {
            for (int i=0; i<myPetals.size()-3; i++) {
                
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
	
    if (bDidICollide == true && bDampedOnCollision == true && !bIsKing){
    		vel *= ofRandom(0.1, 0.4);
    }
}







