#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
	ofGLFWWindowSettings settings;
	settings.width = 600;
	settings.height = 600;
	settings.setPosition(ofVec2f(300, 300));
	settings.resizable = true;
	shared_ptr<ofAppBaseWindow> mainWindow = ofCreateWindow(settings);

	settings.width = 600;
	settings.height = 900;
	settings.setPosition(ofVec2f(0, 300));
	settings.resizable = true;

	shared_ptr<ofAppBaseWindow> guiWindow = ofCreateWindow(settings);
	guiWindow->setVerticalSync(false);

	shared_ptr<ofApp> mainApp(new ofApp);
	mainApp->setupGui();
	ofAddListener(guiWindow->events().draw, mainApp.get(), &ofApp::drawGui);
	ofAddListener(guiWindow->events().keyPressed, mainApp.get(), &ofApp::keyPressed);
	//ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(mainWindow, mainApp);

	ofRunMainLoop();


}
