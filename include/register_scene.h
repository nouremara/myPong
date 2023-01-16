/** The Register scene for the application.

  This scene contains the welcoming text along with the instructions about
  how to play the game. Instructions will show the controls used to
   control the paddles and a guide how to start the game (i.e. goto into court
   scene).
 */
#ifndef MYPONG_REGISTER_SCENE_H
#define MYPONG_REGISTER_SCENE_H

#include "scene.h"

#include <string>

struct SDL_Texture;

namespace myPong {
class Game;

class RegisterScene : public Scene {
public:
  RegisterScene(Game &game);
  virtual ~RegisterScene();

  void onDraw(SDL_Renderer &renderer) override;
  void onUpdate() override;
  void onEnter() override;
  void onExit() override;
  void onKeyDown(SDL_KeyboardEvent &event) override;
  void onKeyUp(SDL_KeyboardEvent &event) override;
  void onTextInpt(std::string &text) override;
  void onMouseClick(int buttonID, int mouseX, int mouseY) override;

  void onButtonClickSelected(int index);
  void drawFocusBox(SDL_Renderer &renderer, int index);
  bool logIn();

private:
  Game &mGame;
  SDL_Texture *mBackgroundImage;
  int focusIndex;
  std::string mInputUserName;
  std::string mInputPassword;
};
} // namespace myPong

#endif // MYPONG_REGISTER_SCENE_H