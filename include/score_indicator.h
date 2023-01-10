/** A score indicator for the application.

    Score indicators are used to show the current score state for the users.
    Typically a Pong gameplay scene contains two score indicators at the each
    side of the center line. One score indicator is assigned for each player.
 */
#ifndef MYPONG_SCORE_INDICATOR_H
#define MYPONG_SCORE_INDICATOR_H

#include "game.h"

#include <SDL.h>

namespace myPong
{
  class ScoreIndicator final
  {
  public:
    ScoreIndicator(Game& thisGame, int x, int y, int width, int height);

    void onDraw(SDL_Renderer& renderer);
    void setValue(int value) { mValue = value; }
  private:
    Game& mGame;
    SDL_Rect mRect;
    int mValue;
  };
}

#endif
