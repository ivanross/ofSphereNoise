#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
  ofSetVerticalSync(true);
  ofEnableDepthTest();

  camera.position = glm::vec3(0, 0, 2);
  camera.fov = glm::radians(90.f);

  dirLight.direction = glm::vec3(0.5, 0, -1);
  dirLight.color = glm::vec3(1);
  dirLight.intensity = .5;

  sphere = ofMesh::sphere(1, 250);

  shader.load("noisy");

  ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::update()
{
  dirLight.direction = glm::vec3(sin(ofGetElapsedTimef()), cos(ofGetElapsedTimef()), -1);
}

//--------------------------------------------------------------
void ofApp::draw()
{
  using namespace glm;

  float time = ofGetElapsedTimef();
  mat4 model = rotate(time * 0.2f, vec3(1, 1, 1));
  mat4 mvp = camera.getProj() * camera.getView() * model;

  shader.begin();
  shader.setUniformMatrix4f("mvp", mvp);
  shader.setUniformMatrix4f("model", model);
  shader.setUniformMatrix3f("normal", mat3(transpose(inverse(model))));
  shader.setUniform3f("lightDir", dirLight.getDirection());
  shader.setUniform3f("lightCol", dirLight.getColor());
  shader.setUniform3f("cameraPos", camera.position);
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
