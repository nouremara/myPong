#include "ball.h"
#include "court_scene.h"

using namespace myPong;

const float Ball::INITIAL_VELOCITY = 8.f;
const float Ball::VELOCITY_INCREASE = 1.f;
const float Ball::MAX_VELOCITY = 15.f;

Ball::Ball(CourtScene &scene, int x, int y, int width, int height)
    : mScene(scene),
      mBallImage(nullptr),
      mRect({x, y, width, height}),
      mVelocity(INITIAL_VELOCITY),
      mDirection({-0.5f, 0.5f})
{
  // calculate half width and height.
  auto halfWidth = (width / 2);
  auto halfHeight = (height / 2);

  // construct an CollisionDetector for the object.
  mCollisionDetector.setCenterX(x + halfWidth);
  mCollisionDetector.setCenterY(y + halfHeight);
  mCollisionDetector.setExtentX(halfWidth);
  mCollisionDetector.setExtentY(halfHeight);

  mBallImage = mScene.getGame().createImage("./assets/ball.png");
}

void Ball::onDraw(SDL_Renderer &renderer)
{
  if (mBallImage != nullptr){
    // draw the background image
    SDL_RenderCopy(&renderer, mBallImage, nullptr, &mRect);
    return;
  }
  
  // else draw a rect.
  SDL_RenderFillRect(&renderer, &mRect);
}

void Ball::onUpdate()
{
  // create an array which contains the movement.
  auto movement = std::array<int, 2>();
  movement[0] = static_cast<int>(mDirection[0] * mVelocity);
  movement[1] = static_cast<int>(mDirection[1] * mVelocity);

  // apply the movement for the position of the ball.
  mRect.x += movement[0];
  mRect.y += movement[1];

  // apply the movement for the position of the CollisionDetector.
  mCollisionDetector.setCenterX(mCollisionDetector.getCenterX() + movement[0]);
  mCollisionDetector.setCenterY(mCollisionDetector.getCenterY() + movement[1]);

  // get references to all possible collision candidates.
  const auto &bottomWallCollisionDetector = mScene.getBottomWall().getCollisionDetector();
  const auto &topWallCollisionDetector = mScene.getTopWall().getCollisionDetector();
  const auto &leftPaddleCollisionDetector = mScene.getLeftPaddle().getCollisionDetector();
  const auto &rightPaddleCollisionDetector = mScene.getRightPaddle().getCollisionDetector();
  const auto &leftGoalCollisionDetector = mScene.getLeftGoal().getCollisionDetector();
  const auto &rightGoalCollisionDetector = mScene.getRightGoal().getCollisionDetector();

  if (mCollisionDetector.collides(bottomWallCollisionDetector))
  {
    // prevent the ball from moving through the wall.
    mRect.y = bottomWallCollisionDetector.getCenterY();
    mRect.y -= bottomWallCollisionDetector.getExtentY();
    mRect.y -= mRect.h;

    // ensure that the CollisionDetector position gets updated as well.
    mCollisionDetector.setCenterX(mRect.x + mCollisionDetector.getExtentX());
    mCollisionDetector.setCenterY(mRect.y + mCollisionDetector.getExtentY());

    // invert the y-axis direction.
    mDirection[1] = -mDirection[1];

    //play hit wall sound
    mScene.getGame().playSoundEffect(2);
  }
  else if (mCollisionDetector.collides(topWallCollisionDetector))
  {
    // prevent the ball from moving through the wall.
    mRect.y = topWallCollisionDetector.getCenterY();
    mRect.y += topWallCollisionDetector.getExtentY();

    // ensure that the CollisionDetector position gets updated as well.
    mCollisionDetector.setCenterX(mRect.x + mCollisionDetector.getExtentX());
    mCollisionDetector.setCenterY(mRect.y + mCollisionDetector.getExtentY());

    // invert the y-axis direction.
    mDirection[1] = -mDirection[1];

    //play hit wall sound
    mScene.getGame().playSoundEffect(2);
  }
  else if (mCollisionDetector.collides(leftPaddleCollisionDetector))
  {
    // prevent the ball from moving through the paddle.
    mRect.x = leftPaddleCollisionDetector.getCenterX();
    mRect.x += leftPaddleCollisionDetector.getExtentX();

    // ensure that the CollisionDetector position gets updated as well.
    mCollisionDetector.setCenterX(mRect.x + mCollisionDetector.getExtentX());
    mCollisionDetector.setCenterY(mRect.y + mCollisionDetector.getExtentY());

    // invert the y-axis direction.
    mDirection[0] = -mDirection[0];

    // increase the velocity if possible.
    mVelocity += VELOCITY_INCREASE;
    mVelocity = std::min(mVelocity, MAX_VELOCITY);

    //play ball hit paddel sound
    mScene.getGame().playSoundEffect(1);
  }
  else if (mCollisionDetector.collides(rightPaddleCollisionDetector))
  {
    // prevent the ball from moving through the paddle.
    mRect.x = rightPaddleCollisionDetector.getCenterX();
    mRect.x -= rightPaddleCollisionDetector.getExtentX();
    mRect.x -= mRect.w;

    // ensure that the CollisionDetector position gets updated as well.
    mCollisionDetector.setCenterX(mRect.x + mCollisionDetector.getExtentX());
    mCollisionDetector.setCenterY(mRect.y + mCollisionDetector.getExtentY());

    // invert the y-axis direction.
    mDirection[0] = -mDirection[0];

    // increase the velocity if possible.
    mVelocity += VELOCITY_INCREASE;
    mVelocity = std::min(mVelocity, MAX_VELOCITY);

    //play ball hit paddel sound
    mScene.getGame().playSoundEffect(1);
  }
  else if (mCollisionDetector.collides(rightGoalCollisionDetector))
  {
    mScene.addPlayerScore(0);

    //play goal sound
    mScene.getGame().playSoundEffect(3);
    
    // wait before processing the next frame
    SDL_Delay(50);  //milliseconds of delay
  }
  else if (mCollisionDetector.collides(leftGoalCollisionDetector))
  {
    mScene.addPlayerScore(1);

     //play goal sound
    mScene.getGame().playSoundEffect(3);
  }
}
