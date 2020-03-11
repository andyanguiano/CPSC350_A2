#include "RunGame.h"

void RunGame::playGame(){
  //variables
  //decisions
  string startDecision = "";
  string gameMode = "";
  string outputDecision = "";
  string fileName = "";

  Grid *gameGrid = new Grid();
  //make a new classic mode here. classic mode makes a grid.
  //1.
  cout << "Would you like to start with a random configuration or read a flat file?" << endl;
  cout << "(random / file)" << endl;
  cin >> startDecision;


  //2.
  cout << "What kind of boundary mode?" << endl;
  cout << "(classic / doughnut / mirror)" << endl;
  cin >> gameMode;

  //3
  cout << "Would you like a brief pause, press enter, or output to file" << endl;
  cout << "(pause / enter / file)"<< endl;
  cin >> outputDecision;


  //1 
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

  //3 Output decision
  if(outputDecision == "pause"){
    //run the pause

  }else if(outputDecision == "enter"){
    //run teh pause
  }else if(outputDecision == "file"){
    cout << "What is the file name: " << endl;
    cin >> fileName;
    //output to file

  }else{
    cout << "That was not an option" << endl;
  }

  //2 GameMode
  if(gameMode == "classic"){
    //run classic game mode class
    ClassicMode play = ClassicMode(gameGrid);
    play.throughBoard();
  }else if(gameMode == "doughnut"){
    //run douhgnut game mode
  }else if(gameMode == "mirror"){
    //run mirror game mode
  }else{
    cout << "That was not an option" << endl;
  }
}
