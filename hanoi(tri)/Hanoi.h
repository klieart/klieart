#ifndef HANOI_H
#define HANOI_H

#include <iostream>
#include <conio.h>
#include <string>
#include <ctime>
#include "peg.h"

using namespace std;

class Hanoi
{
private:
  Peg** pegs;
  int count;
  int discNum;
  time_t startTime;
  time_t endTime;

  void doRecurse(int from, int to, int n);
  void move(int from, int to,int disc);

public:
  Hanoi(int n);
  double getTime();
  int getCount();
  void runHanoi();
};

#endif // HANOI_H
