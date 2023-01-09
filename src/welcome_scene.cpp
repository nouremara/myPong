#include "welcome_scene.h"
#include "court_scene.h"
#include "game.h"

#include <SDL.h>

using namespace myPong;

WelcomeScene::WelcomeScene(Game &game)
    : mGame(game), mBackgroundImage(nullptr), mTopicTexture(nullptr),
      mLeftPlayerInstructions(nullptr), mRightPlayerInstructions(nullptr),
      mContinueInstructions(nullptr), focusIndex(0) {
  mBackgroundImage = mGame.createImage("./assets/intro.png");

  if (mBackgroundImage == nullptr) {
    mTopicTexture = mGame.createText("SDL2 PONG");
    mLeftPlayerInstructions =
        mGame.createText("Controls for the left player: W and S");
    mRightPlayerInstructions = mGame.createText(
        "Controls for the right player: UP-ARROW and DOWN-ARROW");
    mContinueInstructions =
        mGame.createText("Press [ENTER] to start the match");
  }
}

WelcomeScene::~WelcomeScene() {
  if (mBackgroundImage != nullptr) {
    SDL_DestroyTexture(mBackgroundImage);
  } else {
    SDL_DestroyTexture(mTopicTexture);
    SDL_DestroyTexture(mLeftPlayerInstructions);
    SDL_DestroyTexture(mRightPlayerInstructions);
    SDL_DestroyTexture(mContinueInstructions);
  }
}

void WelcomeScene::onDraw(SDL_Renderer &renderer) {
  if (mBackgroundImage != nullptr) {
    // draw the background image
    SDL_RenderCopy(&renderer, mBackgroundImage, nullptr, nullptr);

    // draw foucs box indicator
    drawFocusBox(renderer, focusIndex);

    // render input text
    if (!mInputUserName.empty()) {
      SDL_Rect rect{505, 44, 145, 30};
      SDL_Texture *texture = mGame.createText(mInputUserName.c_str());
      SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);
      SDL_RenderCopy(&renderer, texture, nullptr, &rect);
    }

    // render input text
    if (!mInputPassword.empty()) {
      SDL_Rect rect{505, 84, 145, 30};
      SDL_Texture *texture = mGame.createText(mInputPassword.c_str());
      SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);
      SDL_RenderCopy(&renderer, texture, nullptr, &rect);
    }

    return;
  }

  // else draw native blocks

  // draw the topic of the game.
  SDL_Rect rect{0, 100, 0, 0};
  SDL_QueryTexture(mTopicTexture, nullptr, nullptr, &rect.w, &rect.h);
  rect.x = (400 - (rect.w / 2));
  SDL_RenderCopy(&renderer, mTopicTexture, nullptr, &rect);

  // draw the left player control instructions.
  SDL_QueryTexture(mLeftPlayerInstructions, nullptr, nullptr, &rect.w, &rect.h);
  rect.x = (400 - (rect.w / 2));
  rect.y = 200;
  SDL_RenderCopy(&renderer, mLeftPlayerInstructions, nullptr, &rect);

  // draw the right player control instructions.
  SDL_QueryTexture(mRightPlayerInstructions, nullptr, nullptr, &rect.w,
                   &rect.h);
  rect.x = (400 - (rect.w / 2));
  rect.y = 250;
  SDL_RenderCopy(&renderer, mRightPlayerInstructions, nullptr, &rect);

  // draw the instructions how to continue to court scene.
  SDL_QueryTexture(mContinueInstructions, nullptr, nullptr, &rect.w, &rect.h);
  rect.x = (400 - (rect.w / 2));
  rect.y = 400;
  SDL_RenderCopy(&renderer, mContinueInstructions, nullptr, &rect);
}

void WelcomeScene::onUpdate() {
  // ...
}

void WelcomeScene::onEnter() {
  // ...
}

void WelcomeScene::onExit() {
  // ...
}

void WelcomeScene::onKeyDown(SDL_KeyboardEvent &/*event*/) {
  // ...
}

void WelcomeScene::onKeyUp(SDL_KeyboardEvent &event) {
  // move player into the court scene to start the match.
  switch (event.keysym.sym) {
  case SDLK_RETURN:
    onButtonClickSelected(focusIndex);
    break;

  case SDLK_UP:
    --focusIndex;
    if (focusIndex < 0) {focusIndex = 5;}
    //play hit wall sound
    mGame.playSoundEffect(1);
    break;

  case SDLK_DOWN:
    ++focusIndex;
    if (focusIndex > 5) {focusIndex = 0;}
    //play hit wall sound
    mGame.playSoundEffect(1);
    break;

  case SDLK_F2:
      // start the game directly
      onButtonClickSelected(3);
    break;
  }
}

void WelcomeScene::onTextInpt(std::string &text) {
  // std::cout << text;
  if (focusIndex == 0) {
    mInputUserName = text;
  }
  if (focusIndex == 1) {
    mInputPassword = text;
  }
}

void WelcomeScene::onButtonClickSelected(int index) {
  switch (index) {
  case 2:
    logIn();
    break;
  case 3:
    mGame.setScene(std::make_shared<CourtScene>(mGame));
    break;
  }
}

bool WelcomeScene::logIn() {
  std::cout << "\nlogin function: " << mInputUserName <<"password: " << mInputPassword;
  return false;
}

void WelcomeScene::drawFocusBox(SDL_Renderer &renderer, int index) {
  // draw focus rect
  SDL_SetRenderDrawColor(&renderer, 0xff, 0, 0, 0xff);

  SDL_Rect rect{500, (45 + index * 40), 145, 30};
  SDL_RenderDrawRect(&renderer, &rect);

  // turn back the renderer draw color to white.
  SDL_SetRenderDrawColor(&renderer, 0xff, 0xff, 0xff, 0xff);
}