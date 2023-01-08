#include "game.h"
#include "welcome_scene.h"

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

#include <iostream>

#define ERROR -1
#define OK 0

using namespace myPong;

Game::Game()
    : mWindow(nullptr), mRenderer(nullptr), mFont(nullptr),
      wallHitSound(nullptr), paddleHitSound(nullptr), mResolution({800, 600}),
      mHalfResolution({mResolution[0] / 2, mResolution[1] / 2}),
      mPlayerScores({0, 0}), currentUser() {
  // ...
}

Game::~Game() {
  //SDL_StopTextInput();

  Mix_FreeChunk(wallHitSound);
  Mix_FreeChunk(paddleHitSound);
  TTF_CloseFont(mFont);
  SDL_DestroyWindow(mWindow);
  
  Mix_Quit();
  TTF_Quit();
  SDL_Quit();
}

void Game::start() {
  // initialize the SDL2 framework along with systems.
  if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
    std::cerr << "Unable to initialize SDL: " << SDL_GetError() << std::endl;
    return;
  }

  // initialize the TTF framework for the text rendering.
  if (TTF_Init() == -1) {
    std::cerr << "Unable to initialize TTF: " << TTF_GetError() << std::endl;
    return;
  }

  // try to create a new window for the application.
  mWindow = SDL_CreateWindow("myPong - Nour Emara", SDL_WINDOWPOS_CENTERED,
                             SDL_WINDOWPOS_CENTERED, mResolution[0],
                             mResolution[1], SDL_WINDOW_SHOWN);
  if (mWindow == nullptr) {
    std::cerr << "Unable to create SDL window: " << SDL_GetError() << std::endl;
    return;
  }

  // try to create a new renderer for the application window.
  mRenderer = SDL_CreateRenderer(
      mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (mRenderer == nullptr) {
    std::cerr << "Unable to create SDL renderer: " << SDL_GetError()
              << std::endl;
    return;
  }

  // initialize the font we want to use within our application.
  mFont = TTF_OpenFont("./assets/AntonioBold.ttf", 20);
  if (mFont == nullptr) {
    std::cerr << "Unable to load a font for the application: " << TTF_GetError()
              << std::endl;
  }

  // Initialize sound effects
  // Mix_OpenAudio (frequency, format, channels, chunksize)
  Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
  wallHitSound = Mix_LoadWAV("./assets/WallHit.wav");
  if (wallHitSound == nullptr) {
    std::cerr << "Unable to load sound effects for the application: "
              << Mix_GetError() << std::endl;
  }

  paddleHitSound = Mix_LoadWAV("./assets/PaddleHit.wav");
  if (paddleHitSound == nullptr) {
    std::cerr << "Unable to load sound effects for the application: "
              << Mix_GetError() << std::endl;
  }

  errorSound = Mix_LoadWAV("./assets/error.wav");
  if (errorSound == nullptr) {
    std::cerr << "Unable to load sound effects for the application: "
              << Mix_GetError() << std::endl;
  }

  goalSound = Mix_LoadWAV("./assets/goal.wav");
  if (goalSound == nullptr) {
    std::cerr << "Unable to load sound effects for the application: "
              << Mix_GetError() << std::endl;
  }

  // set the initial scene for the game.
  setScene(std::make_shared<WelcomeScene>(*this));

  auto isRunning = true;
  SDL_Event event;
  while (isRunning) {
    // poll and handle events from the SDL framework.
    while (SDL_PollEvent(&event) != 0) {
      switch (event.type) {
      case SDL_QUIT:
        isRunning = false;
        break;

      case SDL_KEYDOWN:
       if (event.key.keysym.sym == SDLK_BACKSPACE && mTextInput.size()) {
          mTextInput.pop_back();
        }
        if ((event.key.keysym.sym == SDLK_DOWN) || (event.key.keysym.sym == SDLK_UP) ) {
          mTextInput.clear();
        }
        mScene->onKeyDown(event.key);
        break;

      case SDL_KEYUP:
        mScene->onKeyUp(event.key);
        break;

      case SDL_TEXTINPUT:
        mTextInput += event.text.text;
        mScene->onTextInpt(mTextInput);
        break;
      }
    }

    // update game logics on the current scene.
    mScene->onUpdate();

    // clear the rendering context with the black color.
    SDL_SetRenderDrawColor(mRenderer, 0x00, 0x00, 0x00, 0xff);
    SDL_RenderClear(mRenderer);

    // turn the renderer draw color to white.
    SDL_SetRenderDrawColor(mRenderer, 0xff, 0xff, 0xff, 0xff);

    // render scene stuff into the buffer.
    mScene->onDraw(*mRenderer);

    // present the rendered buffer.
    SDL_RenderPresent(mRenderer);
  }
}

void Game::setScene(ScenePtr scene) {
  // skip the null scene assignment.
  if (scene == nullptr) {
    std::cerr << "Unable to set null as the active scene!" << std::endl;
    return;
  }

  // tell old scene (if any) that we are going to exit from it.
  if (mScene) {
    mScene->onExit();
  }

  // assign and enter the new scene.
  mScene = scene;
  mScene->onEnter();
}

SDL_Texture *Game::createText(const std::string &text) {
  // create a surface which contains the desired text.
  SDL_Color color{0xff, 0xff, 0xff, 0xff};
  auto surface = TTF_RenderText_Blended(mFont, text.c_str(), color);
  if (surface == nullptr) {
    std::cerr << "Unable to create a surface with a text: " << TTF_GetError()
              << std::endl;
    return nullptr;
  }

  // create a texture from the text surface.
  auto texture = SDL_CreateTextureFromSurface(mRenderer, surface);
  SDL_FreeSurface(surface);
  if (texture == nullptr) {
    std::cerr << "Unable to create texture from a text surface: "
              << SDL_GetError() << std::endl;
    return nullptr;
  }

  return texture;
}

SDL_Texture *Game::createImage(const char *fileName) {
  /*
  //SDL_Surface* image = SDL_LoadBMP("./assets/checkerboard.png");
  SDL_Surface* img = SDL_LoadBMP(fileName);
    if (img == nullptr) {
        std::cerr << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
        return nullptr;
    }

    // create a texture from the text surface.
    //SDL_Texture* texture = SDL_CreateTextureFromSurface(mRenderer, image);

    */

  SDL_Texture *texture = IMG_LoadTexture(mRenderer, fileName);
  if (texture == nullptr) {
    std::cerr << "SDL_CreateTextureFromSurface Error: " << SDL_GetError()
              << std::endl;
    return nullptr;
  }

  /*
  SDL_FreeSurface(img);
  */
  return texture;
}

void Game::playSoundEffect(int soundClipIndex) {
  switch (soundClipIndex) {
  case 1:
    Mix_PlayChannel(-1, paddleHitSound, 0);
    break;
  case 2:
    Mix_PlayChannel(-1, wallHitSound, 0);
    break;
  case 3:
    Mix_PlayChannel(-1, goalSound, 0);
    break;

  default:
    Mix_PlayChannel(-1, errorSound, 0);
    break;
  }
}
