#pragma once

#include "ofMain.h"

struct CameraData
{
	glm::vec3 position;
	float fov;

	glm::mat4 getProj()
	{
		float aspect = (float)ofGetWidth() / ofGetHeight();
		return glm::perspective(fov, aspect, 0.01f, 1000.f);
	}

	glm::mat4 getView()
	{
		return glm::translate(-1 * position);
	}
};

struct DirectionalLight
{
	glm::vec3 direction;
	glm::vec3 color;
	float intensity;

	glm::vec3 getDirection()
	{
		return glm::normalize(-1.f * direction);
	}
	glm::vec3 getColor()
	{
		return intensity * color;
	}
};

class ofApp : public ofBaseApp
{

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	CameraData camera;
	DirectionalLight dirLight;

	ofShader shader;
	ofMesh sphere;
};
