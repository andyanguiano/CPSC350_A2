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
  }else if(m_mode == "mirror"){
    MirrorMode* game = new MirrorMode(m_matrix);
    playMirror(game, m_outputType);
  }
}


void RunGame::printToConsole(int**matrix, int row, int column){
  for(int i = 0; i < row; ++i){
    for(int j = 0; j < column; ++j){
      int cell = matrix[i][j];
      if(cell == 0) {
        cout << "-";
      }else if(cell == 1){

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
        outfs << "-";
      } else if (cell == 1) {
        outfs << "X";
      }
    }
    outfs << endl;
  }
}

void RunGame::playClassic(ClassicMode *classic, string outputType){
  if(outputType == "pause"){
    while(true){
      cout << "Generation: " << m_genCount << endl;

      printToConsole(mainMatrix, m_row, m_column);

      checkMatrix = classic->throughMatrix(m_matrix, mainMatrix);
      cout << endl;

      m_genCount += 1;

      //printToConsole(checkMatrix, m_row, m_column);

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
  }else if(outputType == "enter"){
    while(true){
      cout << "Generation: " << m_genCount << endl;

      printToConsole(mainMatrix, m_row, m_column);

      checkMatrix = classic->throughMatrix(m_matrix, mainMatrix);
      cout << endl;

      m_genCount += 1;

      //printToConsole(checkMatrix, m_row, m_column);

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
      cout << "Press Enter" << endl;
      cin.ignore();
    }
  }else if(outputType == "file"){
    string fileName = "";
    cout << "Name of the file: ";
    cin >> fileName;

    outfs.open(fileName);

    while(true){
      outfs << "Generation: " << m_genCount << endl;

      printToFile(mainMatrix, m_row, m_column);
      outfs << endl;

      checkMatrix = classic->throughMatrix(m_matrix, mainMatrix);

      m_genCount += 1;

      //printToFile(checkMatrix, m_row, m_column);

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
        outfs << "Stablized" << endl;
        outfs << "End of Game" << endl;
        break;
      }

      for(int i = 0; i < m_row; ++i){
        for(int j = 0; j < m_column; ++j){
          mainMatrix[i][j] = checkMatrix[i][j];
        }
      }
    }
    cout << "Printed to file." << endl;
    outfs.close();
  }
}
