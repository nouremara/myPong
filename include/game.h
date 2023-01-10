// Nour Ahmed
// Matrikal-Nr.: 5200991
// Assignment – Game Implementation

/**========================================================================
 * @file      game.h
 * @brief     The game instance for the whole application.
 *
 * This is the main instance for the whole Pong game application. This class
 * encapsulates the required functionality to tie the application as a whole
 * by combining and providing a way to manage the game state and scenes as 
 * well as the management of performing logical game updates (i.e. ticks).
 *
 * @author    Nour Ahmed
 * @email     nahmed@stud.hs-bremen.de, nour
 * @repo      https://github.com/nouremara/myPong
 * @createdOn 05.01.2023
 * @version   1.0.0
 *========================================================================**/

#ifndef MYPONG_GAME_H
#define MYPONG_GAME_H

#include "scene.h"
#include "userinfo.h"
#include "sqlitedatabase.h"

#include <array>
#include <string>

// SDL forward declarations.
struct SDL_Window;
struct SDL_Renderer;
struct SDL_Texture;
struct _TTF_Font;
struct Mix_Chunk;

namespace myPong
{
  // the game will end when score corsses this limit.
  // and the winner is the one that scores 1 goal more than this number
  const int MAX_GOALS_TO_WIN = 1;

  class Game
  {
  public:
    Game();
    Game(const Game&) = delete;
    Game(Game&&) = delete;

    Game& operator=(const Game&) = delete;
    Game& operator=(Game&&) = delete;

    ~Game();
		
    void start();

    void setScene(ScenePtr scene);

    /*
    * Create SDL_Texture with a given text.
    * @param text: The text to be used for the texture
    */
    SDL_Texture* createText(const std::string& text);
    
    /*
    * Create SDL_Texture from a given image file.
    * @param fileName: The path of the png image file to be used for the texture
    */
    SDL_Texture* createImage(const char *fileName);
    void playSoundEffect(int soundClipIndex);
    int ShowDialogBox(const std::string& title, const std::string& message);
    int ShowSimpleDialogBox(const std::string &title, const std::string &message, const int &dialogType=1);

    bool checkUser(const std::string desiredUserName = "", const std::string desiredUserPassword = "");
    UserInfo& getCurrentUser(){return currentUser;}    
    

    SDL_Renderer*  getRenderer(){return mRenderer;}

    /* Get the resolution (in a 2d-array) of the game canvas. */
    const std::array<int, 2>& getResolution() const { return mResolution; }

    /* Get the half-resolution (in a 2d-array) of the game canvas. */
    const std::array<int, 2>& getHalfResolution() const { return mHalfResolution; }

    /* Get a reference to the player scores via a 2d-array. */
    std::array<int, 2>& getPlayerScores() { return mPlayerScores; }
  private:
    SDL_Window*        mWindow;
    SDL_Renderer*      mRenderer;
    _TTF_Font*         mFont;
    Mix_Chunk*         wallHitSound;
	  Mix_Chunk*         paddleHitSound;
    Mix_Chunk*         errorSound;
    Mix_Chunk*         goalSound;
    ScenePtr           mScene;
    std::array<int, 2> mResolution;
    std::array<int, 2> mHalfResolution;
    std::array<int, 2> mPlayerScores;

    SQLiteDatabase gameDB;
    UserInfo currentUser;
    std::string mTextInput;
  };
}

#endif