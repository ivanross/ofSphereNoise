#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{

  // GL
  ofSetVerticalSync(true);
  ofDisableArbTex();
  ofEnableDepthTest();

  // CAMERA

  camera.position = glm::vec3(0, 0, 2);
  camera.fov = glm::radians(90.f);

  // LIGHTS
  ambientLight.color = glm::vec3(1, 1, 1);
  ambientLight.intensity = 0.85;

  dirLight.direction = glm::vec3(0, -1, -1);
  dirLight.color = glm::vec3(1);
  dirLight.intensity = 1;

  sphere = ofMesh::sphere(1, 250);

  shader.load("noisy");
  skyboxShader.load("skybox");

  cubemap.load(
      "skybox/front.png",
      "skybox/back.png",
      "skybox/right.png",
      "skybox/left.png",
      "skybox/top.png",
      "skybox/bottom.png");
}

//--------------------------------------------------------------
void ofApp::update()
{
  camera.angle += ofGetLastFrameTime() * 0.33;
}

//--------------------------------------------------------------
void ofApp::draw()
{
  drawSkybox();
  drawNoisySphere();
}

void ofApp::drawNoisySphere()
{
  using namespace glm;

  float time = ofGetElapsedTimef();
  mat4 model = mat4();
  mat4 mvp = camera.getProj() * camera.getView() * model;

  shader.begin();
  shader.setUniformMatrix4f("mvp", mvp);
  shader.setUniformMatrix4f("model", model);
  shader.setUniformMatrix3f("normal", mat3(transpose(inverse(model))));
  shader.setUniform3f("lightDir", dirLight.getDirection());
  shader.setUniform3f("lightCol", dirLight.getColor());
  shader.setUniform3f("ambientCol", ambientLight.getColor());
  shader.setUniform3f("cameraPos", camera.getPosition());
  shader.setUniform1f("time", time);
  shader.setUniformTexture("envMap", cubemap.getTexture(), 0);
  sphere.draw();
  shader.end();
}

void ofApp::drawSkybox()
{
  using namespace glm;

  mat4 model = translate(camera.getPosition());
  mat4 mvp = camera.getProj() * camera.getView() * model;
  glDepthFunc(GL_LEQUAL);
  skyboxShader.begin();
  skyboxShader.setUniformMatrix4f("mvp", mvp);
  skyboxShader.setUniformTexture("envMap", cubemap.getTexture(), 0);
  skyboxShader.setUniform3f("ambientCol", ambientLight.getColor());
  skybox.draw();
  skyboxShader.end();
  glDepthFunc(GL_LESS);
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
