#include <iostream>
#include <fstream>
#include <random>

using namespace std;

//class to create a grid
class Grid{
  public:
    Grid();
    Grid(int row, int column, float density);
    ~Grid();

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

    //temp
    //int main(int argc, char **argv);


  private:
    int m_row;
    int m_column;
    float m_density;

};
