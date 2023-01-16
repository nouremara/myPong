#include "endgame_scene.h"
#include "welcome_scene.h"

#include <SDL.h>
#include <memory>

using namespace myPong;

EndgameScene::EndgameScene(Game &game)
    : mGame(game), 
      mTitleTextTexture(nullptr), 
      mEndgameTexture(nullptr),
      mWinnerTexture(nullptr), 
      mEndResultTexture(nullptr),
      mResultScoreTexture(nullptr), 
      mInstructionsTexture(nullptr), 
      mBackgroundImage(nullptr) 
{
  mBackgroundImage = mGame.createImage("./assets/final.png");

  // get a reference to the overall score.
  const auto &scores = mGame.getPlayerScores();

  mTitleTextTexture = mGame.createText("myPong - Game Ended");
  mEndgameTexture = mGame.createText("RESULTS");
  mEndResultTexture = mGame.createText("Left player : Right player");
  mResultScoreTexture = mGame.createText(std::to_string(scores[0]) + " : " +
                                         std::to_string(scores[1]));

  if (scores[0] > 9) {
    mWinnerTexture = mGame.createText("Winner is : Left player");
  } else {
    std::string rightWinnerName =
        "Winner is :  " + mGame.getCurrentUser().userName;
    mWinnerTexture = mGame.createText(rightWinnerName.c_str());
  }

  mInstructionsTexture = mGame.createText("Press [ENTER] to proceed");
}

EndgameScene::~EndgameScene() {
  if (mBackgroundImage != nullptr) {
    SDL_DestroyTexture(mBackgroundImage);
  }

  SDL_DestroyTexture(mTitleTextTexture);
  SDL_DestroyTexture(mEndgameTexture);
  SDL_DestroyTexture(mEndResultTexture);
  SDL_DestroyTexture(mResultScoreTexture);
  SDL_DestroyTexture(mWinnerTexture);
  SDL_DestroyTexture(mInstructionsTexture);
}

void EndgameScene::onDraw(SDL_Renderer &renderer) {
  if (mBackgroundImage != nullptr) {
    // draw the background image
    SDL_RenderCopy(&renderer, mBackgroundImage, nullptr, nullptr);
  }

  // draw the topic of the game.
  SDL_Rect rect{400, 50, 0, 0};
  SDL_QueryTexture(mTitleTextTexture, nullptr, nullptr, &rect.w, &rect.h);
  rect.x = (590 - (rect.w / 2));
  SDL_RenderCopy(&renderer, mTitleTextTexture, nullptr, &rect);

  rect.y = 100;
  SDL_QueryTexture(mEndgameTexture, nullptr, nullptr, &rect.w, &rect.h);
  rect.x = (590 - (rect.w / 2));
  SDL_RenderCopy(&renderer, mEndgameTexture, nullptr, &rect);

  rect.y = 150;
  SDL_QueryTexture(mEndResultTexture, nullptr, nullptr, &rect.w, &rect.h);
  rect.x = (590 - (rect.w / 2));
  SDL_RenderCopy(&renderer, mEndResultTexture, nullptr, &rect);

  rect.y = 190;
  SDL_QueryTexture(mResultScoreTexture, nullptr, nullptr, &rect.w, &rect.h);
  rect.x = (590 - (rect.w / 2));
  SDL_RenderCopy(&renderer, mResultScoreTexture, nullptr, &rect);

  rect.y = 250;
  SDL_QueryTexture(mWinnerTexture, nullptr, nullptr, &rect.w, &rect.h);
  rect.x = (590 - (rect.w / 2));
  SDL_RenderCopy(&renderer, mWinnerTexture, nullptr, &rect);

  rect.y = 300;
  SDL_QueryTexture(mInstructionsTexture, nullptr, nullptr, &rect.w, &rect.h);
  rect.x = (590 - (rect.w / 2));
  SDL_RenderCopy(&renderer, mInstructionsTexture, nullptr, &rect);
}

void EndgameScene::onUpdate() {
  // ...
}

void EndgameScene::onEnter() {
  // ...
}

void EndgameScene::onExit() {
  // ...
}

void EndgameScene::onKeyDown(SDL_KeyboardEvent & /*event*/) {
  // ...
}

void EndgameScene::onKeyUp(SDL_KeyboardEvent &event) {
  // move player back to the welcome scene.
  switch (event.keysym.sym) {
  case SDLK_RETURN:
    mGame.setScene(std::make_shared<WelcomeScene>(mGame));
    break;
  }
}

void EndgameScene::onTextInpt(std::string & /*text*/) {
  // ...
}

void EndgameScene::onMouseClick(int buttonID, int mouseX, int mouseY){
    std::string mouseCoord = "Left button was pressed!\n button pressed:"+
    std::to_string(buttonID) + 
    "\n X: " + std::to_string(mouseX) + 
    " Y: " + std::to_string(mouseY);
  mGame.ShowSimpleDialogBox("Mouse", mouseCoord.c_str());
}