#ifndef _TEST_APP
#define _TEST_APP

#include "ofxOpenNI.h"
#include "ofMain.h"
#define MAX_DEVICES 2

//----osc
#include "ofxOsc.h"
#define HOST "localhost"
#define PORT 12345

class testApp : public ofBaseApp{
    
public:
    
	void setup();
	void update();
	void draw();
    void exit();
    
	void keyPressed  (int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
    
    //--osc
    ofTrueTypeFont font;
    ofxOscSender sender;
    
private:
    
    void handEvent(ofxOpenNIHandEvent & event);
    
	ofxOpenNI openNIDevice;
    ofTrueTypeFont verdana;
    
};

#endif
