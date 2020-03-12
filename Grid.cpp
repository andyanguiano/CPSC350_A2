#include "Grid.h"
//default
Grid::Grid(){
  m_row = 0;
  m_column = 0;
  m_density = 0.0;
}
//overloaded
Grid::Grid(int row, int column, float density){
  m_row = row;
  m_column = column;
  m_density = density;
}
//delete
Grid::~Grid(){
  delete matrix;
}
//returns row column and density
int Grid::getRow(){
  return m_row;
}
int Grid::getColumn(){
  return m_column;
}
float Grid::getDensity(){
  return m_density;
}
//sets rows columns and density
void Grid::setRow(int row){
  m_row = row;
}
void Grid::setColumn(int column){
  m_column = column;
}
void Grid::setDensity(float density){
  m_density = density;
}
//returns matrix
int** Grid::getMatrix(){
  return matrix;
}

//return board
//creates a grid from random configurations
void Grid::createRandom(int row, int column, float density){
  //creates blank grid
  matrix = new int*[row];
  for(int i = 0; i < row; ++i){
    matrix[i] = new int[column];
  }
  //populates with random float based on density
  for(int i = 0; i < row; ++i){
    for(int j = 0; j < column; ++j){
      //generate number between 0 and 1
      float temp = rand()% 100;
      temp /= 100;
      if(density <= temp){
        matrix[i][j] = 1;
      }else{
        matrix[i][j] = 0;
      }
    }
  }
}
//creates grid from file
void Grid::createFile(string file){
  ifstream infs;
  infs.open(file);
  string currentLine = "";
  int lineCount = 1;
  int i = 0;
  //error checking
  if(!infs.is_open()){
    cout << "Could not open file. Start program over." << endl;
  }
  //gets every line and sets variables
  while(infs >> currentLine){
    if(!infs.fail()){
      if(lineCount == 1){
        m_row = stoi(currentLine);
        cout << m_row << endl;
      }else if(lineCount == 2){
        m_column = stoi(currentLine);
        //creates grid
        matrix = new int*[m_row];
        for(int i = 0; i < m_row; ++i){
          matrix[i] = new int[m_column];
        }
      }else{
        //populates grid
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
