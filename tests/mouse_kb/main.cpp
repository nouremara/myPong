// source: https://bitbucket.org/dandago/gigilabs/src/fd9e428beeccdbc3b07f2813941669e92d6803e6/Sdl2KeyboardMouse/?at=master
#include <sstream>
#include <SDL.h>

int main(int argc, char ** argv)
{
    // variables

    bool quit = false;
    SDL_Event event;
    int x = 288;
    int y = 208;

    // init SDL

    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window * window = SDL_CreateWindow("SDL2 Keyboard/Mouse events",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
    SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);

    SDL_Surface * image = SDL_LoadBMP("spaceship.bmp");
    SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, image);
    SDL_FreeSurface(image);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    // handle events

    while (!quit)
    {
        SDL_Delay(20);
        SDL_PollEvent(&event);
        
        std::string mouseCoord;

        switch (event.type)
        {
            case SDL_QUIT:
                quit = true;
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                case SDLK_LEFT:  x--; break;
                case SDLK_RIGHT: x++; break;
                case SDLK_UP:    y--; break;
                case SDLK_DOWN:  y++; break;
                }
                break;
            case SDL_MOUSEBUTTONDOWN:
                switch (event.button.button)
                {
                case SDL_BUTTON_LEFT:
                    mouseCoord = "Left button was pressed!\n button pressed:"+std::to_string(event.button.button) + "\n X: " + std::to_string(event.motion.x) + " Y: " + std::to_string(event.motion.y);
                    SDL_ShowSimpleMessageBox(0, "Mouse", mouseCoord.c_str(), window);
                    break;
                case SDL_BUTTON_MIDDLE:
                    mouseCoord = "Middle button was pressed!\n button pressed:"+std::to_string(event.button.button) + "\n X: " + std::to_string(event.motion.x) + " Y: " + std::to_string(event.motion.y);
                    SDL_ShowSimpleMessageBox(0, "Mouse", mouseCoord.c_str(), window);
                    break;
                case SDL_BUTTON_RIGHT:
                    mouseCoord = "Right button was pressed!\n button pressed:"+std::to_string(event.button.button) + "\n X: " + std::to_string(event.motion.x) + " Y: " + std::to_string(event.motion.y);
                    SDL_ShowSimpleMessageBox(0, "Mouse", mouseCoord.c_str(), window);
                    break;
                case SDL_BUTTON_X1:
                    SDL_ShowSimpleMessageBox(0, "Mouse", "X1 button was pressed!", window);
                    break;
                case SDL_BUTTON_X2:
                    SDL_ShowSimpleMessageBox(0, "Mouse", "X2 button was pressed!", window);
                    break;
                default:
                    SDL_ShowSimpleMessageBox(0, "Mouse", "Some other button was pressed!", window);
                    break;
                }
                break;
            case SDL_MOUSEMOTION:
                int mouseX = event.motion.x;
                int mouseY = event.motion.y;

                std::stringstream ss;
                ss << "X: " << mouseX << " Y: " << mouseY;

                SDL_SetWindowTitle(window, ss.str().c_str());
                break;
        }

        SDL_Rect dstrect = { x, y, 64, 64 };

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture, NULL, &dstrect);
        SDL_RenderPresent(renderer);
    }

    // cleanup SDL

    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}