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
  infs.open(file);
  string currentLine = "";
  int lineCount = 1;
  int i = 0;


  while(!infs.eof()){
    infs >> currentLine;
    if(!infs.fail()){
      if(lineCount == 1){
        m_row = stoi(currentLine);
      }else if(lineCount == 2){
        m_column = stoi(currentLine);
        //matrix
        matrix = new int*[m_row];
        for(int i = 0; i < m_row; ++i){
          matrix[i] = new int[m_column];
        }
      }else{
        for(int j = 0; j < m_column; ++j){
          char currentChar = currentLine[j];
          if(currentChar == 'X'){
            matrix[i][j] = 1;
          }else if(currentChar == '-'){
            matrix[i][j] = 0;
          }
        }
        ++i;
      }
    }
    ++lineCount;
  }
  infs.close();
}
