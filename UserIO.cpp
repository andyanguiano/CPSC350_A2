#include "UserIO.h"

UserIO::UserIO(){
  m_matrix = NULL;
  m_modeType = "";
  m_outputType = "";
}

UserIO::~UserIO(){
  delete m_matrix;
}

void UserIO::start(){
  m_matrix = promptFileRandom();
  m_modeType = promptMode();
  m_outputType = promptOutputType();
}

Grid* UserIO::promptFileRandom(){
  string startDecision = "";
  Grid *gameGrid = new Grid();

  cout << "Would you like to start with a random configuration or read a flat file?" << endl;
  cout << "(random / file)" << endl;
  cin >> startDecision;

  if(startDecision == "random"){
    int rowChoice = 0;
    int columnChoice = 0;
    float densityChoice = 0.0;
    //create random grid with class
    cout << "How many rows?:" << endl;
    cin >> rowChoice;
    gameGrid->setRow(rowChoice);
    cout << "How many columns?:" << endl;
    cin >> columnChoice;
    gameGrid->setColumn(columnChoice);
    cout << "A decimal percentage of initial bacteria?: " << endl;
    cin >> densityChoice;
    gameGrid->setDensity(densityChoice);

    //creates the random
    gameGrid->createRandom(rowChoice, columnChoice, densityChoice);

  }else if(startDecision == "file"){
    //create grid with read file
    string fileName = "";
    cout << "What is the file name?: " << endl;
    cin >> fileName;
    gameGrid->createFile(fileName);
  }else{
    cout << "That was not an option" << endl;
  }
  return gameGrid;
}

string UserIO::promptMode(){
  string gameMode = "";

  cout << "What kind of boundary mode?" << endl;
  cout << "(classic / doughnut / mirror)" << endl;
  cin >> gameMode;

  return gameMode;
}

string UserIO::promptOutputType(){
  string outputDecision = "";

  cout << "Would you like a brief pause, press enter, or output to file?" << endl;
  cout << "(pause / enter / file)"<< endl;
  cin >> outputDecision;
  cout << endl;

  return outputDecision;
}

Grid* UserIO::getMatrix(){
  return m_matrix;
}
string UserIO::getModeType(){
  return m_modeType;
}
string UserIO::getOutputType(){
  return m_outputType;
}
