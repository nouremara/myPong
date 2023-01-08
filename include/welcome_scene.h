/** The welcome scene for the application.

  This scene contains the welcoming text along with the instructions about
  how to play the game. Instructions will show the controls used to
   control the paddles and a guide how to start the game (i.e. goto into court
   scene).
 */
#ifndef MYPONG_WELCOME_SCENE_H
#define MYPONG_WELCOME_SCENE_H

#include "scene.h"

#include <string>

struct SDL_Texture;

namespace myPong {
class Game;

class WelcomeScene : public Scene {
public:
  WelcomeScene(Game &game);
  virtual ~WelcomeScene();

  void onDraw(SDL_Renderer &renderer) override;
  void onUpdate() override;
  void onEnter() override;
  void onExit() override;
  void onKeyDown(SDL_KeyboardEvent &event) override;
  void onKeyUp(SDL_KeyboardEvent &event) override;
  void onTextInpt(std::string &text) override;
  
  void onButtonClickSelected(int index);
  void drawFocusBox(SDL_Renderer &renderer, int index);
  bool logIn();

private:
  Game &mGame;
  SDL_Texture *mBackgroundImage;
  SDL_Texture *mTopicTexture;
  SDL_Texture *mLeftPlayerInstructions;
  SDL_Texture *mRightPlayerInstructions;
  SDL_Texture *mContinueInstructions;
  int focusIndex;
  std::string mInputUserName;
  std::string mInputPassword;
};
} // namespace myPong

#endif