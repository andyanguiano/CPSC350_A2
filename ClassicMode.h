#include "Grid.cpp"

using namespace std;

//class to play the classic game mode
class ClassicMode{
  public:
    ClassicMode();
    ClassicMode(Grid *matrix);
    ~ClassicMode();

    int countNeighbors(int i, int j, int row, int column, int** b);

    int nextGenStatus(int previousStatus, int numNeighbors);

    void throughBoard();

    int** m_matrix;

    Grid *m_classicMatrix;


};
