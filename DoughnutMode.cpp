#include "DoughnutMode.h"
//default constructor
DoughnutMode::DoughnutMode(){
  m_classicMatrix = NULL;
}
//overlaoded constructor
DoughnutMode::DoughnutMode(Grid *m){
  m_classicMatrix = m;
}
//delete
DoughnutMode::~DoughnutMode(){
  delete m_classicMatrix;
}
//counts number of neighbors for doughnut mode
int DoughnutMode::countNeighbors(int i, int j, int row, int column, Grid *matrix){
  int **currMatrix = matrix->getMatrix();
  int count = 0;
  //corners
  if(i == 0){
    if(j == 0){
      //upper left corner
      //checks 8 neighbors
      if(currMatrix[i][j+1] == 1){
        count += 1;
      }
      if(currMatrix[i+1][j+1] == 1){
        count += 1;
      }
      if(currMatrix[i+1][j] == 1){
        count += 1;
      }
      //downleft
      if(currMatrix[i+1][column-1] == 1){
        count += 1;
      }
      //left
      if(currMatrix[i][column-1] == 1){
        count += 1;
      }
      //upperleft
      if(currMatrix[row-1][column-1] == 1){
        count += 1;
      }
      //up
      if(currMatrix[row-1][j] == 1){
        count += 1;
      }
      //upperright
      if(currMatrix[row-1][j+1] == 1){
        count += 1;
      }

    }else if(j == column - 1){
      //upper right corner
      //left
      if(currMatrix[i][j-1] == 1){
        count += 1;
      }
      //downleft
      if(currMatrix[i+1][j-1] == 1){
        count += 1;
      }
      //down
      if(currMatrix[i+1][j] == 1){
        count += 1;
      }
      //downright
      if(currMatrix[i+1][0] == 1){
        count += 1;
      }
      //right
      if(currMatrix[i][0] == 1){
        count += 1;
      }
      //upleft
      if(currMatrix[row-1][0] == 1){
        count += 1;
      }
      //up
      if(currMatrix[row-1][j] == 1){
        count += 1;
      }
      //upperleft
      if(currMatrix[row-1][j-1] == 1){
        count += 1;
      }
    }else{
      //check top row 5 neighbors
      //left
      if(currMatrix[i][j-1] == 1){
        count += 1;
      }
      //downleft
      if(currMatrix[i+1][j-1] == 1){
        count += 1;
      }
      //down
      if(currMatrix[i+1][j] == 1){
        count += 1;
      }
      //right
      if(currMatrix[i][j+1] == 1){
        count += 1;
      }
      //downright
      if(currMatrix[i+1][j+1] == 1){
        count += 1;
      }
      //upperright
      if(currMatrix[row-1][j+1] == 1){
        count += 1;
      }
      //up
      if(currMatrix[row-1][j] == 1){
        count += 1;
      }
      //upleft
      if(currMatrix[row-1][j-1] == 1){
        count += 1;
      }
    }
  }else if(i == row - 1){
    if(j == 0){
      //down left corner
      //up
      if(currMatrix[i-1][j] == 1){
        count += 1;
      }
      //upperright
      if(currMatrix[i-1][j+1] == 1){
        count += 1;
      }
      //right
      if(currMatrix[i][j+1] == 1){
        count += 1;
      }
      //downright
      if(currMatrix[0][j+1] == 1){
        count += 1;
      }
      //down
      if(currMatrix[0][j] == 1){
        count += 1;
      }
      //downleft
      if(currMatrix[0][column-1] == 1){
        count += 1;
      }
      //left
      if(currMatrix[i][column-1] == 1){
        count += 1;
      }
      //upleft
      if(currMatrix[i-1][column-1] == 1){
        count += 1;
      }
    }else if(j == column - 1){
      //down right corner
      //left
      if(currMatrix[i][j-1] == 1){
        count += 1;
      }
      //upperleft
      if(currMatrix[i-1][j-1] == 1){
        count += 1;
      }
      //up
      if(currMatrix[i-1][j] == 1){
        count += 1;
      }
      //upperright
      if(currMatrix[i-1][0] == 1){
        count += 1;
      }
      //right
      if(currMatrix[i][0] == 1){
        count += 1;
      }
      //downright
      if(currMatrix[0][0] == 1){
        count += 1;
      }
      //down
      if(currMatrix[0][j] == 1){
        count += 1;
      }
      //downleft
      if(currMatrix[0][j-1] == 1){
        count += 1;
      }

    }else{
      //bottom row 5 neighbors
      //left
      if(currMatrix[i][j-1] == 1){
        count += 1;
      }
      //upperleft
      if(currMatrix[i-1][j-1] == 1){
        count += 1;
      }
      //up
      if(currMatrix[i-1][j] == 1){
        count += 1;
      }
      //upperright
      if(currMatrix[i-1][j+1] == 1){
        count += 1;
      }
      //right
      if(currMatrix[i][j+1] == 1){
        count += 1;
      }
      //downright
      if(currMatrix[0][j+1] == 1){
        count += 1;
      }
      //down
      if(currMatrix[0][j] == 1){
        count += 1;
      }
      //down left
      if(currMatrix[0][j-1] == 1){
        count += 1;
      }
    }
  }else if(j == 0){
    //left column remaining 5 neighbors
    //up
    if(currMatrix[i-1][j] == 1){
      count += 2;
    }
    //upper right
    if(currMatrix[i-1][j+1] == 1){
      count += 1;
    }
    //right
    if(currMatrix[i][j+1] == 1){
      count += 1;
    }
    //down right
    if(currMatrix[i+1][j+1] == 1){
      count += 1;
    }
    //down
    if(currMatrix[i+1][j] == 1){
      count += 2;
    }
    //down left
    if(currMatrix[i+1][column-1] == 1){
      count += 1;
    }
    //left
    if(currMatrix[i][column-1] == 1){
      count += 1;
    }
    //upperleft
    if(currMatrix[i-1][column-1] == 1){
      count += 1;
    }
  }else if(j == column - 1){
    //right column remaining
    //up
    if(currMatrix[i-1][j] == 1){
      count += 2;
    }
    //upper left
    if(currMatrix[i-1][j-1] == 1){
      count += 1;
    }
    //left
    if(currMatrix[i][j-1] == 1){
      count += 1;
    }
    //downleft
    if(currMatrix[i+1][j-1] == 1){
      count += 1;
    }
    //down
    if(currMatrix[i+1][j] == 1){
      count += 1;
    }
    //downright
    if(currMatrix[i+1][0] == 1){
      count += 1;
    }
    //right
    if(currMatrix[i][0] == 1){
      count += 1;
    }
    //upperright
    if(currMatrix[i-1][0] == 1){
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
//see whether cell will be alive next generation
int DoughnutMode::nextGenStatus(int previousStatus, int count){
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
//iterates through matrix
int** DoughnutMode::throughMatrix(Grid *matrix, int **current){
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
