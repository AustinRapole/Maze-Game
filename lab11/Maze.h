#ifndef MAZE__H
#define MAZE__H

#include <vector>
#include <fstream>
#include <iostream>
#include "Coordinate.h"
//#include "Gen.h"

using namespace std;

class Maze{
  public:
    void load(string filename);
    void save(string filename);
    vector<string> getData(Coordinate loc, int radius);
    vector<Coordinate> locationOf(char ch);
    char getSymbol(Coordinate loc);
    void setSymbol(Coordinate loc, char c);
    bool isValid(Coordinate c);
  //  void Generate();
 
   //generate(int w, int h); 
  private:
    vector<string> symbols;
};

#endif
