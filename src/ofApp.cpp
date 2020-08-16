#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
  ofSetVerticalSync(true);
  ofEnableDepthTest();

  camera.position = glm::vec3(0, 0, 2);
  camera.fov = glm::radians(90.f);

  sphere = ofMesh::sphere(1, 250);
  shader.load("noisy");

  ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::update()
{
}

//--------------------------------------------------------------
void ofApp::draw()
{
  using namespace glm;

  float time = ofGetElapsedTimef();
  mat4 model = rotate(time * 0.2f, vec3(1, 1, 1));

  shader.begin();
  shader.setUniformMatrix4f("mvp", camera.getProj() * camera.getView() * model);
  shader.setUniform1f("time", time);
  sphere.draw();
  shader.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{
}
