/*
Andy Anguiano & Thomas Moore
Game of Life
CPSC350_A2
*/
#include "UserIO.h"
//plays the game of life
int main(int argc, char **argv) {

  UserIO *userIO = new UserIO();
  userIO->start();

  string modeInput = userIO->getModeType();
  string outputType = userIO->getOutputType();

  RunGame* game = new RunGame(userIO->getMatrix(), modeInput, outputType);
  game->play();

  return 0;
}
