#ifndef HANOI_H
#define HANOI_H

#include <iostream>
#include <conio.h>
#include <string>
#include "CTimer.h"
#include "peg.h"

using namespace std;

class Hanoi
{
private:
  Peg** pegs;
  int moves;
  int discNum;
  CTimer qTimer;
  void recursion(int from, int to, int n);
  void move(int from, int to,int disc);

public:
  Hanoi(int n);
  void runHanoi();
  int getMoves();
  double getTime();
};

#endif // HANOI_H
