// Nour Ahmed
// Matrikal-Nr.: 5200991
// Assignment – Game Implementation

/**========================================================================
 * @file  main.cpp
 * @brief The entry point of the application.
 *
 * This is the entry point for the classical Pong game implemented
 * with the SDL2 library. This entry point contains a simple logic where we
 * only create, start and close the application as required.
 * See the other files for more interesting details how the
 * actual game is implemented.
 *
 * @author    Nour Ahmed
 * @email     nahmed@stud.hs-bremen.de
 * @repo      https://github.com/nouremara/myPong
 * @createdOn 05.01.2023
 * @version   1.0.0
 *========================================================================**/

#include "game.h"

using namespace myPong;

int main(int argc, char* args[])
{
  Game game;
  game.start();
  return 0;
}