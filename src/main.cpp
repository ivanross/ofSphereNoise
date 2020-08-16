#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main()
{
	// ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context

	ofGLWindowSettings settings;
	settings.setGLVersion(4, 1);
	settings.setSize(1024, 768);
	settings.windowMode = OF_WINDOW;
	ofCreateWindow(settings);

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());
}
