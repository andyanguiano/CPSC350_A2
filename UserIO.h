#include "RunGame.h"

class UserIO{
  public:
    UserIO();
    ~UserIO();
    Grid *m_matrix;
    string m_modeType;
    string m_outputType;

    void start();

    Grid* promptFileRandom();
    string promptMode();
    string promptOutputType();

    Grid* getMatrix();
    string getModeType();
    string getOutputType();
};
