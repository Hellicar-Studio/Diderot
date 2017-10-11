#pragma once

#include "ofMain.h"
#include "ofxDiderotApp.h"
#include "ofxCv.h"

class ofApp : public ofxDiderotApp{

	public:
		void setup();
		void setupGui();
		void update();
		void draw();
		void drawGui(ofEventArgs & args);

		void exposureChanged(int & val);
		void playingChanged(bool & val);
        void fullscreenChanged(bool & val);
		void onFolderChanged(ofAbstractParameter &p);

		void keyPressed(int key);
		void keyPressed(ofKeyEventArgs & args);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        ofVec4f convertColorToUniformRange(ofColor col);

		ofParameter<int> exposure;
		ofParameter<bool> playing;
		ofParameter<float> percent;
		ofParameter<bool> negative;
		ofParameter<float> scale;
		ofParameter<bool> rotate;
		ofParameter<bool> fullscreen;
		ofParameter<float> threshold;
        ofParameter<ofColor> tint;
        ofParameter<float> contrast;
		vector<ofParameter<bool>> folders;

		ofFbo buff;
    
        int startTime;
        int timeBetweenSwaps;
        int lastSwapTime;
    
        bool wasPlaying;

		ofParameterGroup foldersGroup;

		ofSoundPlayer player;

		ofShader negativeEffect;
    
        int numFiles;
        float fps;
        float spf;
};
