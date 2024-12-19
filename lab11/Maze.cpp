#include "Maze.h"

void Maze::load(string filename){
  ifstream fin;
  fin.open(filename);
  string line;
  symbols.clear();
  while(getline(fin,line)){
    symbols.push_back(line);
  }
  fin.close();
}

void Maze::save(string filename){
  ofstream fout;
  fout.open(filename);
  for(string s: symbols){
    fout << s << endl;
  }
  fout.close();
}

vector<string> Maze::getData(Coordinate loc, int radius){
  vector<string> rv;
  for(int y = -radius; y <= radius; ++y){
    string line = "";
    for(int x = -radius; x <= radius; ++x){
      Coordinate c = Coordinate(x,y) + loc;
      if(c.y >= 0 and c.x >= 0 and c.y < symbols.size() and c.x < symbols[c.y].size()){
	line += symbols[c.y][c.x];
      }else{
	line += " ";
      }

    }
    rv.push_back(line);
  }
  return rv;
}

vector<Coordinate> Maze::locationOf(char ch){
  vector<Coordinate> rv;
  for(int i = 0; i <symbols.size(); ++i){
    for(int j = 0; j < symbols[i].size(); ++j){
      if(symbols[i][j] == ch){
	rv.push_back(Coordinate(j,i));
      }
    }
  }
  return rv;
}

char Maze::getSymbol(Coordinate loc){
  if(loc.x < 0 or loc.y < 0 or loc.y >= symbols.size() or loc.x >= symbols[loc.y].size()){
    return '\n';
  }
  return symbols[loc.y][loc.x];
}

void  Maze::setSymbol(Coordinate loc, char c){
  if(loc.x < 0 or loc.y < 0 or loc.y >= symbols.size() or loc.x >= symbols[loc.y].size()){
    return;
  }
  symbols[loc.y][loc.x] = c;
}

bool Maze::isValid(Coordinate c){
  Coordinate loc;
  if(c.x < 0 or c.y < 0 or c.y >= symbols.size() or c.x >= symbols[c.y].size()){
    return false;
  }else if(symbols[c.y][c.x] == '#'){
    return false;
  }
  return true;
}

/*void Maze::Generate(){
  Gen g;
  symbols = g.Generate();
  symbols[1][1] ='s';
}*/
