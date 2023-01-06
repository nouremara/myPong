#include "center_line.h"

using namespace myPong;

CenterLine::CenterLine(int x, int y, int width, int height) : mRect({ x, y, width, height })
{
  // ...
}

void CenterLine::onDraw(SDL_Renderer& renderer)
{
  // draw the center line by forming a number squares as required.
  for (float y = static_cast<float>(mRect.y); y < mRect.h; y += (1.93f * mRect.w)) {
    SDL_Rect rect{ mRect.x, static_cast<int>(y), mRect.w, mRect.w };

    // change the renderer draw color to white.
    //SDL_SetRenderDrawColor(&renderer, 0xcc, 0xff, 0x33, 0x50);
    SDL_RenderFillRect(&renderer, &rect);

    // turn back the renderer draw color to white.
    //SDL_SetRenderDrawColor(&renderer, 0xff, 0xff, 0xff, 0xff);
  }
}