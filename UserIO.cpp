#include "UserIO.h"
//default
UserIO::UserIO(){
  m_matrix = NULL;
  m_modeType = "";
  m_outputType = "";
}
//delete
UserIO::~UserIO(){
  delete m_matrix;
}
//prompts for all user input
void UserIO::start(){
  m_matrix = promptFileRandom();
  m_modeType = promptMode();
  m_outputType = promptOutputType();
}
//prompts for how to create grid
Grid* UserIO::promptFileRandom(){
  string startDecision = "";
  Grid *gameGrid = new Grid();
  while(startDecision != "random" && startDecision != "file"){
    cout << "Would you like to start with a random configuration or read a flat file?" << endl;
    cout << "(random / file)" << endl;
    cin >> startDecision;
    cout << endl;
    if(startDecision != "random" && startDecision != "file"){
      cout << "That was not an option" << endl;
    }
  }
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
//prompts what mode to play
string UserIO::promptMode(){
  string gameMode = "";
  while(gameMode != "classic" && gameMode != "doughnut" && gameMode != "mirror"){
    cout << "What kind of boundary mode?" << endl;
    cout << "(classic / doughnut / mirror)" << endl;
    cin >> gameMode;
  }
  return gameMode;
}
//prompts hoe to output game
string UserIO::promptOutputType(){
  string outputDecision = "";

  cout << "Would you like a brief pause, press enter, or output to file?" << endl;
  cout << "(pause / enter / file)"<< endl;
  cin >> outputDecision;
  cout << endl;

  return outputDecision;
}
//get Matrix
Grid* UserIO::getMatrix(){
  return m_matrix;
}
//get mode type
string UserIO::getModeType(){
  return m_modeType;
}
//get output type
string UserIO::getOutputType(){
  return m_outputType;
}
