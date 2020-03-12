#include "MirrorMode.h"
//default
MirrorMode::MirrorMode(){
  m_classicMatrix = NULL;
}
//overloaded
MirrorMode::MirrorMode(Grid *m){
  m_classicMatrix = m;
}
//delete
MirrorMode::~MirrorMode(){
  delete m_classicMatrix;
}
//counts the number of neighbors for mirror game mode
int MirrorMode::countNeighbors(int i, int j, int row, int column, Grid *matrix){
  //takes matrix
  int **currMatrix = matrix->getMatrix();
  int count = 0;
  //corners
  if(i == 0){
    if(j == 0){
      //upper left corner
      //checks 8 neighbors
      if(currMatrix[i][j+1] == 1){
        count += 2;
      }
      if(currMatrix[i+1][j+1] == 1){
        count += 1;
      }
      if(currMatrix[i+1][j] == 1){
        count += 2;
      }
      if(currMatrix[i][j] == 1){
        count += 3;
      }
    }else if(j == column - 1){
      //upper right corner
      if(currMatrix[i][j-1] == 1){
        count += 2;
      }
      if(currMatrix[i+1][j-1] == 1){
        count += 1;
      }
      if(currMatrix[i+1][j] == 1){
        count += 2;
      }
      if(currMatrix[i][j] == 1){
        count += 3;
      }
    }else{
      //check top row 5 neighbors
      if(currMatrix[i][j-1] == 1){
        count += 2;
      }
      if(currMatrix[i+1][j-1] == 1){
        count += 1;
      }
      if(currMatrix[i+1][j] == 1){
        count += 1;
      }
      if(currMatrix[i][j+1] == 1){
        count += 2;
      }
      if(currMatrix[i+1][j+1] == 1){
        count += 1;
      }
      if(currMatrix[i][j] == 1){
        count += 1;
      }
    }
  }else if(i == row - 1){
    if(j == 0){
      //down left corner
      if(currMatrix[i-1][j] == 1){
        count += 2;
      }
      if(currMatrix[i-1][j+1] == 1){
        count += 1;
      }
      if(currMatrix[i][j+1] == 1){
        count += 2;
      }
      if(currMatrix[i][j] == 1){
        count += 3;
      }
    }else if(j == column - 1){
      //down right corner
      if(currMatrix[i][j-1] == 1){
        count += 2;
      }
      if(currMatrix[i-1][j-1] == 1){
        count += 1;
      }
      if(currMatrix[i-1][j] == 1){
        count += 2;
      }
      if(currMatrix[i][j] == 1){
        count += 3;
      }
    }else{
      //bottom row 5 neighbors
      if(currMatrix[i][j-1] == 1){
        count += 2;
      }
      if(currMatrix[i-1][j-1] == 1){
        count += 1;
      }
      if(currMatrix[i-1][j] == 1){
        count += 1;
      }
      if(currMatrix[i-1][j+1] == 1){
        count += 1;
      }
      if(currMatrix[i][j+1] == 1){
        count += 2;
      }
      if(currMatrix[i][j] == 1){
        count += 1;
      }
    }
  }else if(j == 0){
    //left column remaining 5 neighbors
    if(currMatrix[i-1][j] == 1){
      count += 2;
    }
    if(currMatrix[i-1][j+1] == 1){
      count += 1;
    }
    if(currMatrix[i][j+1] == 1){
      count += 1;
    }
    if(currMatrix[i+1][j+1] == 1){
      count += 1;
    }
    if(currMatrix[i+1][j] == 1){
      count += 2;
    }
    if(currMatrix[i][j] == 1){
      count += 1;
    }
  }else if(j == column - 1){
    //right column remaining
    if(currMatrix[i-1][j] == 1){
      count += 2;
    }
    if(currMatrix[i-1][j-1] == 1){
      count += 1;
    }
    if(currMatrix[i][j-1] == 1){
      count += 1;
    }
    if(currMatrix[i+1][j-1] == 1){
      count += 1;
    }
    if(currMatrix[i+1][j] == 1){
      count += 2;
    }
    if(currMatrix[i][j] == 1){
      count += 1;
    }
  }else{
    //meat count all 8 neighbors
    if(currMatrix[i-1][j] == 1){
      count += 1;
    }
    if(currMatrix[i-1][j-1] == 1){
      count += 1;
    }
    if(currMatrix[i][j-1] == 1){
      count += 1;
    }
    if(currMatrix[i+1][j-1] == 1){
      count += 1;
    }
    if(currMatrix[i+1][j] == 1){
      count += 1;
    }
    if(currMatrix[i+1][j+1] == 1){
      count += 1;
    }
    if(currMatrix[i][j+1] == 1){
      count += 1;
    }
    if(currMatrix[i-1][j+1] == 1){
      count += 1;
    }
  }
  return count;
}
//checks to see how many neighbors whether teh cell will die or live on
int MirrorMode::nextGenStatus(int previousStatus, int count){
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
//iterates through matrix with count neighbors and next gen status
int** MirrorMode::throughMatrix(Grid *matrix, int **current){
  int row = 0;
  row = matrix->getRow();
  int column = 0;
  column = matrix->getColumn();

  //create a new matrix to check values same way in Grid.cpp
  int **checkMatrix = new int*[row];
  for(int i = 0; i < row; ++i){
    checkMatrix[i] = new int[column];
  }

  int prevVal = 0;
  int count = 0;
  
  for (int i = 0; i < row; ++i){
    for (int j = 0; j < column; ++j){
      //count neigbors in m_matrix
      count = countNeighbors(i, j, row, column, matrix);
      //update checkMatrix with nextGenCell
      prevVal = current[i][j];
      checkMatrix[i][j] = nextGenStatus(prevVal, count);
    }
  }
  return checkMatrix;

}
