#ifndef EXPLORER__H
#define EXPLORER__H

#include "Coordinate.h"
#include <fstream>

using namespace std;

struct Explorer{
  Coordinate location;
  int coins = 20;
  int health = 3;
  int bomb = 2;
  int radius = 4;
  int brad = 1;

 void save(string filename);
 void load(string filename);

};

#endif
