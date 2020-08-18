#include "Camera.h"

glm::mat4 Camera::getProj()
{
  float aspect = (float)ofGetWidth() / ofGetHeight();
  return glm::perspective(fov, aspect, 0.01f, 1000.f);
}

glm::mat4 Camera::getView()
{
  glm::mat4 T = glm::translate(-1 * position);
  glm::mat4 RX = glm::rotate(-angleX, glm::vec3(1, 0, 0));
  glm::mat4 RY = glm::rotate(-angleY, glm::vec3(0, 1, 0));
  return T * RX * RY;
}

glm::vec3 Camera::getPosition()
{
  glm::mat3 RX = glm::mat3(glm::rotate(angleX, glm::vec3(1, 0, 0)));
  glm::mat3 RY = glm::mat3(glm::rotate(angleY, glm::vec3(0, 1, 0)));
  return RY * RX * position;
}

void Camera::onMoveStart(int x, int y)
{
  prevX = x;
  prevY = y;
}

void Camera::onMove(int x, int y)
{
  int dx = x - prevX;
  angleY -= dx * speed;
  prevX = x;

  int dy = y - prevY;
  angleX -= dy * speed;
  angleX = glm::clamp<float>(angleX, -PI / 2.f, PI / 2.f);
  prevY = y;
}
void Camera::onMoveEnd()
{
}