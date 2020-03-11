#include "RunGame.h"

RunGame::RunGame(){
  m_matrix = NULL;
  m_mode = "";
  m_genCount = 1;
  m_end = false;
}

RunGame::RunGame(Grid *matrix, string mode, string outputType){
  m_matrix = matrix;
  m_mode = mode;
  m_outputType = outputType;
  m_genCount = 1;
  mainMatrix = matrix->getMatrix();
  m_row = matrix->getRow();
  m_column = matrix->getColumn();
  checkMatrix = NULL;
  m_end = false;
}

RunGame::~RunGame(){
  delete m_matrix;
}

void RunGame::play(){
  if(m_mode == "classic"){
    ClassicMode* game = new ClassicMode(m_matrix);
    playClassic(game, m_outputType);
  }
}


void RunGame::printToConsole(int**matrix, int row, int column) {
  for(int i = 0; i < row; ++i){
    for(int j = 0; j < column; ++j){
      int cell = matrix[i][j];
      if(cell == 0) {
        cout << "-";
      }else if(cell == 1) {
        cout << "X";
      }
    }
    cout << endl;
  }
}

void RunGame::printToFile(int**matrix, int row, int column) {
  for (int i = 0; i < row; ++i) {
    for (int j = 0; j < column; ++j) {
      int cell = matrix[i][j];
      if (cell == 0) {
        //m_outFS << "-";
      } else if (cell == 1) {
        //m_outFS << "X";
      }
    }
  //  m_outFS << endl;
  }
}

void playClassic(ClassicMode *classic, string outputType){
  if (outputType == "pause"){
    while(true){
      cout << "Generation Number" << m_genCount << endl;
      cout << endl;

      printToConsole(mainMatrix, m_row, m_column);
      cout << endl;

      checkMatrix = classic->throughMatrix(m_matrix, mainMatrix);
      cout << endl;

      m_genCount += 1;

      //printToConsole(checkMatrix, m_row, m_column)

      m_end = true;
      for(int i = 0; i < m_row; ++i){
        for(int j = 0; j < m_column; ++j){
          if(checkMatrix[i][j] != mainMatrix[i][j]){
            m_end = false;
            break;
          }
        }
      }

      if(m_end){
        cout << "Stablized" << endl;
        cout << "End of Game" << endl;
        break;
      }

      for(int i = 0; i < m_row; ++i){
        for(int j = 0; j < m_column; ++j){
          mainMatrix[i][j] = checkMatrix[i][j];
        }
      }
    }
    sleep(1);
  }
}
