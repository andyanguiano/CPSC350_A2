#include "ClassicMode.h"
#include "MirrorMode.h"
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <stdio.h>


using namespace std;

class RunGame{
public:
  RunGame();
  RunGame(Grid *matrix, string mode, string outputType);
  ~RunGame();


  void play();

  void playClassic(ClassicMode *classic, string outputType);
  void playMirror(MirrorMode *mirror, string outputType);

  void printToConsole(int** matrix, int row, int column);
  void printToFile(int** matrix, int row, int column);

  Grid* m_matrix;
  int **mainMatrix;
  int **checkMatrix;
  string m_mode;
  string m_outputType;
  int m_row;
  int m_column;
  bool m_end;
  ofstream outfs;

private:
  int m_genCount;

};
