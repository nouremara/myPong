// Nour Ahmed
// Matrikal-Nr.: 5200991
// Assignment – Game Implementation

/**========================================================================
 * @file      goal.h
 * @brief     A goal entity that contains definitions for the game goals.
 *
 * This class contains an implementation for a single pong game goal. Goal is
 * not a visible component but is used to detect when players gain scores.
 *
 * @author    Nour Ahmed
 * @email     nahmed@stud.hs-bremen.de, nour
 * @repo      https://github.com/nouremara/myPong
 * @createdOn 05.01.2023
 * @version   1.0.0
 *========================================================================**/

#ifndef MYPONG_GOAL_H
#define MYPONG_GOAL_H

#include <SDL.h>

#include "collision_detector.h"

namespace myPong
{
  class Goal final
  {
  public:
    Goal(int x, int y, int width, int height);

    void setX(int x) { mRect.x = x; mCollisionDetector.setCenterX(x + mCollisionDetector.getExtentX()); }
    void setY(int y) { mRect.y = y; mCollisionDetector.setCenterY(y + mCollisionDetector.getExtentY()); }

    const CollisionDetector& getCollisionDetector() const { return mCollisionDetector; }
          CollisionDetector& getCollisionDetector()       { return mCollisionDetector; }
  private:
    SDL_Rect          mRect;
    CollisionDetector mCollisionDetector;
  };
}

#endif