#include "goal.h"

using namespace myPong;

Goal::Goal(int x, int y, int width, int height) : mRect({ x, y, width, height })
{
  // calculate the half width and height.
  auto extentX = (width / 2);
  auto extentY = (height / 2);

  // define the dimensions for the CollisionDetector.
  mCollisionDetector.setCenterX(x + extentX);
  mCollisionDetector.setCenterY(y + extentY);
  mCollisionDetector.setExtentX(extentX);
  mCollisionDetector.setExtentY(extentY);
}