#include "Grid.h"

using namespace std;

//class to play the classic game mode
class MirrorMode{
  public:
    MirrorMode();
    MirrorMode(Grid *matrix);
    ~MirrorMode();

    int countNeighbors(int i, int j, int row, int column, Grid *matrix);

    int nextGenStatus(int previousStatus, int numNeighbors);

    int **throughMatrix(Grid *matrix, int **current);

    Grid *m_classicMatrix;


};
