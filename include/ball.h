// Nour Ahmed
// Matrikal-Nr.: 5200991
// Assignment – Game Implementation

/**========================================================================
 * @file      ball.h
 * @brief     The ball entity that contains definitions for the game ball.
 *
 * This class presents the ball entity used in the court scene. Ball is an
 * entity that goes around the scene by bouncing from the other entities.
 *
 * @author    Nour Ahmed
 * @email     nahmed@stud.hs-bremen.de, nour
 * @repo      https://github.com/nouremara/myPong
 * @createdOn 05.01.2023
 * @version   1.0.0
 *========================================================================**/

#ifndef MYPONG_BALL_H
#define MYPONG_BALL_H

#include "collision_detector.h"

#include <SDL.h>
#include <array>

namespace myPong {

class CourtScene;

class Ball {
public:
  /** The initial velocity for the ball. */
  static const float INITIAL_VELOCITY;
  /** The amount of velocity to be added on each paddle hit. */
  static const float VELOCITY_INCREASE;
  /** The maximum velocity for the ball. */
  static const float MAX_VELOCITY;

  Ball(CourtScene &scene, int x, int y, int width, int height);

  void onDraw(SDL_Renderer &renderer);
  void onUpdate();

  void setX(int x) {
    mRect.x = x;
    mCollisionDetector.setCenterX(x + mCollisionDetector.getExtentX());
  }
  void setY(int y) {
    mRect.y = y;
    mCollisionDetector.setCenterY(y + mCollisionDetector.getExtentY());
  }

  void setDirection(const std::array<float, 2> &direction) {
    mDirection = direction;
  }

  void setVelocity(float velocity) { mVelocity = velocity; }

  const CollisionDetector &getCollisionDetector() const {
    return mCollisionDetector;
  }
  CollisionDetector &getCollisionDetector() { return mCollisionDetector; }

private:
  CourtScene &mScene;
  SDL_Texture *mBallImage;
  SDL_Rect mRect;
  CollisionDetector mCollisionDetector;
  float mVelocity;
  std::array<float, 2> mDirection;
};

} // namespace myPong

#endif //MYPONG_BALL_H