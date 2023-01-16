/** The center line entity that contains the center line boxes.

    Note that this entity is not collideable and should not be used in any kind
    of game logic related stuff. It is only used to make the court to look like
    a playfield similar to tennis or other ball games.
 */
#ifndef MYPONG_CENTER_LINE_H
#define MYPONG_CENTER_LINE_H

#include <SDL.h>

namespace myPong
{
  class CenterLine
  {
  public:
    CenterLine(int x, int y, int width, int height);

    void onDraw(SDL_Renderer& renderer);
  private:
    SDL_Rect mRect;
  };
}

#endif