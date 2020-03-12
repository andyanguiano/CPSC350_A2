#include "Grid.h"

using namespace std;

//class to play the classic game mode
class DoughnutMode{
  public:
    DoughnutMode();
    DoughnutMode(Grid *matrix);
    ~DoughnutMode();

    int countNeighbors(int i, int j, int row, int column, Grid *matrix);

    int nextGenStatus(int previousStatus, int numNeighbors);

    int **throughMatrix(Grid *matrix, int **current);

    Grid *m_classicMatrix;


};
