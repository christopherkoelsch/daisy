#ifndef _TEST_APP
#define _TEST_APP

#include "ofxOpenNI.h"
#include "ofMain.h"
#include "followerBig.h"
#include "followerSmall.h"

#define MAX_DEVICES 2

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
    void handPostion();
    
    ofImage                 daisyImage;
    ofImage                 petalImage;
    ofImage                 followerImage;
    ofImage                 petalImageHovered;
    ofImage                 petalImageHovered2;
    ofImage                 BGimage;
    vector<followerBig>     myFlws;
    vector<followerSmall>   myFlwSmall;
    vector<ofPoint>         handPostions;
    
    int                     flwCounter;
    bool                    bEmit;
    bool                    bDebug;
    
private:
    
    void handEvent(ofxOpenNIHandEvent & event);
	ofxOpenNI openNIDevice;
    
};

#endif
