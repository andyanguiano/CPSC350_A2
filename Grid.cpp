#include "Grid.h"


void Grid::grid(){
  int row = 0;
  int column = 0;
  float density = 0.0;
}

void Grid::grid(int row, int column, float density){
  m_row = row;
  m_column = column;
  m_density = density;
}

void ~grid(){
  //delete
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

//return board
int** Grid::createRandom(){
  int matrix = new int*[row];
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
  return matrix;
}

int** Grid::createFile(string file){
  ifstream infs;
  ofstream outfs;

  infs.open(file);

  while(!infs.eof()){
    if(!infs.fail()){
      string line = "";
      getline(infs, line)
      rows = int(line);
      getline(infs,line)
      column = int(line);
      //matrix
      int matrix = new int*[row];
      for(i = 0; i < row; ++i){
        matrix[i] = new int[column];
      }

      int tempRow = -1;
      while(getline(infs, line)){
        ++tempRow;
        int tempColumn = -1;
        foreach(char c in line){ //temp variable c in line
          ++tempColumn;
          if (c == "-"){
            matrix[tempRow][tempColumn] = 0;
          }else if(c == "X"){
            matrix[tempRow][tempColumn] = 1;
          }
        }
      }
    }
  }

  return matrix;

}
