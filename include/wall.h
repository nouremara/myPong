/** A horizontal wall abstraction for the Pong game.

    This class contains a definition for a single horizontal wall for a Pong
    game. Typically Pong contains a wall at the bottom and the top of the
    screen. These walls are also commonly 100% wide related to game scene.
 */
#ifndef MYPONG_WALL_H
#define MYPONG_WALL_H

#include "collision_detector.h"

#include <SDL.h>

namespace myPong
{
  class Wall
  {
  public:
    Wall(int x, int y, int width, int height);

    void onDraw(SDL_Renderer& renderer);

    const CollisionDetector& getCollisionDetector() const { return mCollisionDetector; }
          CollisionDetector& getCollisionDetector()       { return mCollisionDetector; }
  private:
    SDL_Rect mRect;
    CollisionDetector     mCollisionDetector;
  };
}

#endif