#include <iostream>
#include <fstream>
#include <random>

using namespace std;

class Grid{
  public:
    void grid();
    void grid(int row, int column, float density);
    void ~grid();

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
