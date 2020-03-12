#include "UserIO.h"

int main(int argc, char **argv) {

  UserIO *userIO = new UserIO();
  userIO->start();

  string modeInput = userIO->getModeType();
  string outputType = userIO->getOutputType();

  RunGame* game = new RunGame(userIO->getMatrix(), modeInput, outputType);
  game->play();

  return 0;
}
