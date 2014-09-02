#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"

#include "particle.h"

class testApp : public ofSimpleApp{
	
public:
    
    void setup();
    void update();
    void draw();
    
    
    ofImage spot;
    
    void keyPressed  (int key);
    void keyReleased (int key);
    
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased();
    
    // let's make a vector of them
    vector <particle> particles;
	
    void setupArduino(const int & version);
	void updateArduino();
    void arduinoLoop();
    
    //bool pin13;
    //bool ledcommand;
    
	ofArduino	ard;
	bool		bSetupArduino;
    bool ardButtonPressed;
    bool mouse_pressed;
    
    
	
};

#endif

