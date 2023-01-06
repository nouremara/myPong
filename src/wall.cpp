#include "wall.h"

using namespace myPong;

Wall::Wall(int x, int y, int width, int height) : mRect({ x, y, width, height})
{
  // construct an CollisionDetector for the wall.
  mCollisionDetector.setCenterX(x + width / 2);
  mCollisionDetector.setCenterY(y + height / 2);
  mCollisionDetector.setExtentX(width / 2);
  mCollisionDetector.setExtentY(height / 2);
}

void Wall::onDraw(SDL_Renderer& renderer)
{
  SDL_RenderFillRect(&renderer, &mRect);
}
