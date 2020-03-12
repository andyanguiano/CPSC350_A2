/*
Andy Anguiano & Thomas Moore
Game of Life
CPSC350_A2
*/
#include "Grid.h"

using namespace std;

//class to play the Doughnut game mode
class DoughnutMode{
  public:
    DoughnutMode();//defalut
    DoughnutMode(Grid *matrix);//overloaded
    ~DoughnutMode();//delete

    int countNeighbors(int i, int j, int row, int column, Grid *matrix);

    int nextGenStatus(int previousStatus, int numNeighbors);

    int **throughMatrix(Grid *matrix, int **current);

    Grid *m_classicMatrix;


};
