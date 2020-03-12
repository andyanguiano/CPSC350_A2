/*
Andy Anguiano & Thomas Moore
Game of Life
CPSC350_A2
*/
#pragma once
#include <iostream>
#include <fstream>
#include <random>
#include "math.h"

using namespace std;

//class to create a grid
class Grid{
  public:
    Grid();//default construcor
    Grid(int row, int column, float density);//overload constructor
    ~Grid();//delete

    int getRow();
    int getColumn();
    float getDensity();

    void setRow(int row);
    void setColumn(int column);
    void setDensity(float density);
    int** getMatrix();


    int** matrix;

    void createRandom(int row, int column, float density);
    void createFile(string file);

  private:
    int m_row;
    int m_column;
    float m_density;

};
