#include "RunGame"

RunGame::RunGame(
  //variables
  //decisions
  string startDecision = "";
  string gameMode = "";
  string outputDecision = "";
  string fileName = "";

  //1.
  cout << "Would you like to start with a random configuration or read a flat file?" << endl;
  cout << "(random / file)"
  cin >> startDecision;

  //2.
  cout << "What kind of boundary mode?" << endl;
  cout << "(classic / doughnut / mirror)" << endl;
  cin >> gameMode;

  //3
  cout << "Would you like a brief pause, press enter, or output to file" << end;
  cout << "(pause / enter / file)"<< endl;
  cin >> outputDecision;


  //1
  if(tolower(startDecision) == "random"){
    //create random grid with class
  }else if(tolower(startDecision) == "file"){
    //create grid with read file
  }else{
    cout << "That was not an option" << endl;
    break;
  }

  //3
  if(tolower(outputDecision) == "pause"){
    //run the pause

  }else if(tolower(outputDecision) == "enter"){
    //run teh pause
  }else if(tolower(outputDecision) == "file"){
    //output to file
    cout << "What is the file name: " << endl;
    cin >> fileName;

  }else{
    cout << "That was not an option" << endl;
    break;
  }

  //2
  if(tolower(gameMode) == "classic"){
    //run classic game mode class
  }else if(tolower(gameMode) == "doughnut"){
    //run douhgnut game mode
  }else if(tolower(gameMode) == "mirror"){
    //run mirror game mode
  }else{
    cout << "That was not an option" << endl;
    break;
  }






)
