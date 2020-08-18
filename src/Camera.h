#include "ofMain.h"

class Camera
{
public:
  glm::vec3 position;
  float angleY;
  float angleX;
  float fov;
  float speed;

  glm::mat4 getProj();
  glm::mat4 getView();
  glm::vec3 getPosition();

  void onMoveStart(int x, int y);
  void onMove(int x, int y);
  void onMoveEnd();

private:
  float prevX;
  float prevY;
};