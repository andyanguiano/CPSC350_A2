#include <iostream>
#include <fstream>
#include <random>

using namespace std;

class Grid{
  public:
    Grid();
    Grid(int row, int column, float density);
    ~Grid();

    int getRow();
    int getColumn();
    float  getDensity();

    void setRow(int row);
    void setColumn(int column);
    void setDensity(float density);


    int** matrix;

    //return board
    int **createRandom();
    int **createFile(string file);


  private:
    int m_row;
    int m_column;
    float m_density;

};
