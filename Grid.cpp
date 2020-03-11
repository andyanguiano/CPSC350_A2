#include "Grid.h"


Grid::Grid(){
  m_row = 0;
  m_column = 0;
  m_density = 0.0;
}

Grid::Grid(int row, int column, float density){
  m_row = row;
  m_column = column;
  m_density = density;
}

Grid::~Grid(){
  delete matrix;
}

int Grid::getRow(){
  return m_row;
}
int Grid::getColumn(){
  return m_column;
}
float Grid::getDensity(){
  return m_density;
}

void Grid::setRow(int row){
  row = m_row;
}
void Grid::setColumn(int column){
  column = m_column;
}
void Grid::setDensity(float density){
  density = m_density;
}

int** Grid::getMatrix(){
  return matrix;
}

//return board
void Grid::createRandom(int row, int column, float density){
  matrix = new int*[row];
  for(int i = 0; i < row; ++i){
    matrix[i] = new int[column];
  }

  for(int i = 0; i < row; ++i){
    for(int j = 0; j < column; ++j){
      //generate number between 0 and 1
      float temp = rand()% 1+0;
      if(density <= temp){
        matrix[i][j] = 1;
      }else{
        matrix[i][j] = 0;
      }
    }
  }
}

void Grid::createFile(string file){
  ifstream infs;
  ofstream outfs;

  infs.open(file);

  while(!infs.eof()){
    if(!infs.fail()){
      string line = "";
      int row = 0;
      int column = 0;
      getline(infs, line); // not sure
      row = stoi(line);
      getline(infs,line); // not sure
      column = stoi(line);
      //matrix
      matrix = new int*[row];
      for(int i = 0; i < row; ++i){
        matrix[i] = new int[column];
      }

      int tempRow = -1;
      while(getline(infs, line)){
        ++tempRow;
        int tempColumn = -1;
        for(char c : line){ //temp variable c in line
          ++tempColumn;
          if (c == '-'){
            matrix[tempRow][tempColumn] = 0;
          }else if(c == 'X'){
            matrix[tempRow][tempColumn] = 1;
          }
        }
      }
    }
  }
}
