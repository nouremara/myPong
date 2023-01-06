// Nour Ahmed
// Matrikal-Nr.: 5200991
// Assignment – Game Implementation

/**========================================================================
 * @file      paddle.h
 * @brief     A paddle definition and implementation for a Pong game.
 *
 * This class contains the necessary definitions and logics for a single 
 * game paddle instance that is used in the court scene. Paddles are 
 * controlled by player inputs.
 * 
 * @author    Nour Ahmed
 * @email     nahmed@stud.hs-bremen.de, nour
 * @repo      https://github.com/nouremara/myPong
 * @createdOn 05.01.2023
 * @version   1.0.0
 *========================================================================**/

#ifndef MYPONG_PADDLE_H
#define MYPONG_PADDLE_H

#include <SDL.h>

#include "collision_detector.h"

namespace myPong{
  class CourtScene;

  class Paddle{
  public:
    /** The movement velocity for the paddle. */
    static const int VELOCITY;

    /** Enumeration for possible paddle movement directions. */
    enum class Movement : int {
      UP    = -1,
      NONE  =  0,
      DOWN  =  1
    };

    Paddle(CourtScene& scene, int x, int y, int width, int height, bool isLeftPaddel=false);

    void onDraw(SDL_Renderer& renderer);
    void onUpdate();

    void setMovement(Movement movement) { mMovement = movement; }

    bool isMoving(Movement movement) const { return mMovement == movement;  }

    void setX(int x) { mRect.x = x; mCollisionDetector.setCenterX(x + mCollisionDetector.getExtentX()); }
    void setY(int y) { mRect.y = y; mCollisionDetector.setCenterY(y + mCollisionDetector.getExtentY()); }

    const CollisionDetector& getCollisionDetector() const { return mCollisionDetector; }
          CollisionDetector& getCollisionDetector()       { return mCollisionDetector; }
  private:
    CourtScene&       mScene;
    SDL_Rect          mRect;
    Movement          mMovement;
    CollisionDetector mCollisionDetector;
    bool              isLeft;
  };
}

#endif // #define MYPONG_PADDLE_H