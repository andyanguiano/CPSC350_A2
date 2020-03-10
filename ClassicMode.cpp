#include "ClassicMode.h"

ClassicMode::ClassicMode(){
  m_matrix = NULL;
  m_classicMatrix = NULL;
}

ClassicMode::ClassicMode(Grid *m){
  m_classicMatrix = m;
  m_matrix = m->getMatrix();
}

ClassicMode::~ClassicMode(){
  delete m_matrix;
}

int ClassicMode::countNeighbors(int i, int j, int row, int column, int **matrix){
  int count = 0;

  //corners
  if(i == 0){
    if(j == 0){
      //upper left corner
      //checks 3 neighbors
      if(matrix[i][j+1] == 1){
        count += 1;
      }
      if(matrix[i+1][j+1] == 1){
        count += 1;
      }
      if(matrix[i+1][j] == 1){
        count += 1;
      }
    }else if(j == column - 1){
      //upper right corner
      if(matrix[i][j-1] == 1){
        count += 1;
      }
      if(matrix[i+1][j-1] == 1){
        count += 1;
      }
      if(matrix[i+1][j] == 1){
        count += 1;
      }
    }else{
      //check top row 5 neighbors
      if(matrix[i][j-1] == 1){
        count += 1;
      }
      if(matrix[i+1][j-1] == 1){
        count += 1;
      }
      if(matrix[i+1][j] == 1){
        count += 1;
      }
      if(matrix[i][j+1] == 1){
        count += 1;
      }
      if(matrix[i+1][j+1] == 1){
        count += 1;
      }
    }
  }else if(i == row - 1){
    if(j == 0){
      //down left corner
      if(matrix[i-1][j] == 1){
        count += 1;
      }
      if(matrix[i-1][j+1] == 1){
        count += 1;
      }
      if(matrix[i][j+1] == 1){
        count += 1;
      }
    }else if(j == column - 1){
      //down right corner
      if(matrix[i][j-1] == 1){
        count += 1;
      }
      if(matrix[i-1][j-1] == 1){
        count += 1;
      }
      if(matrix[i-1][j] == 1){
        count += 1;
      }
    }else{
      //bottom row 5 neighbors
      if(matrix[i][j-1] == 1){
        count += 1;
      }
      if(matrix[i-1][j-1] == 1){
        count += 1;
      }
      if(matrix[i-1][j] == 1){
        count += 1;
      }
      if(matrix[i-1][j+1] == 1){
        count += 1;
      }
      if(matrix[i][j+1] == 1){
        count += 1;
      }
    }
  }else if(j == 0){
    //left column remaining 5 neighbors
    if(matrix[i-1][j] == 1){
      count += 1;
    }
    if(matrix[i-1][j+1] == 1){
      count += 1;
    }
    if(matrix[i][j+1] == 1){
      count += 1;
    }
    if(matrix[i+1][j+1] == 1){
      count += 1;
    }
    if(matrix[i+1][j] == 1){
      count += 1;
    }
  }else if(j == column - 1){
    //right column remaining
    if(matrix[i-1][j] == 1){
      count += 1;
    }
    if(matrix[i-1][j-1] == 1){
      count += 1;
    }
    if(matrix[i][j-1] == 1){
      count += 1;
    }
    if(matrix[i+1][j-1] == 1){
      count += 1;
    }
    if(matrix[i+1][j] == 1){
      count += 1;
    }
  }else{
    //meat count all 8 neighbors
    if(matrix[i-1][j] == 1){
      count += 1;
    }
    if(matrix[i-1][j-1] == 1){
      count += 1;
    }
    if(matrix[i][j-1] == 1){
      count += 1;
    }
    if(matrix[i+1][j-1] == 1){
      count += 1;
    }
    if(matrix[i+1][j] == 1){
      count += 1;
    }
    if(matrix[i+1][j+1] == 1){
      count += 1;
    }
    if(matrix[i][j+1] == 1){
      count += 1;
    }
    if(matrix[i-1][j+1] == 1){
      count += 1;
    }
  }
  return count;
}

int ClassicMode::nextGenStatus(int previousStatus, int count){
  int newCell = 0;
  if (count <= 1) {
    newCell = 0;
  } else if (count == 2) {
    newCell = previousStatus;
  } else if (count == 3) {
    newCell = 1;
  } else if (count >= 4) {
    newCell = 0;
  }
  return newCell;
}

void ClassicMode::throughBoard(){
  int row = 0;
  row = m_classicMatrix->getRow();
  int column = 0;
  column = m_classicMatrix->getColumn();

  m_matrix = m_classicMatrix->getMatrix();

  int checkMatrix[row][column];
  int checkVal = 0;
  int count = 1;

  for (int i = 0; i < row; ++i){
    for (int j = 0; j < column; ++j){
      //not sure
    }
  }
}
