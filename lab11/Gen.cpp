#include "Gen.h"

#define GRID_WIDTH 79
#define GRID_HEIGHT 23

#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

char grid[GRID_WIDTH*GRID_HEIGHT];

void Gen::ResetGrid(){
  for(int i =0; i<GRID_WIDTH*GRID_HEIGHT;++i){
    grid[i] = '#';
  }
}

int Gen::XYToIndex( int x, int y ){
  return y * GRID_WIDTH + x;
}

int Gen::IsInBounds( int x, int y ){
  if (x < 0 || x >= GRID_WIDTH) return false;
  if (y < 0 || y >= GRID_HEIGHT) return false;
  return true;
}

void Gen::Visit( int x, int y ){
  grid[ XYToIndex(x,y) ] = ' ';
  int dirs[4];
  dirs[0] = NORTH;
  dirs[1] = EAST;
  dirs[2] = SOUTH;
  dirs[3] = WEST;
  for (int i=0; i<4; ++i)
  {
    int r = rand() & 3;
    int temp = dirs[r];
    dirs[r] = dirs[i];
    dirs[i] = temp;
  }
  for (int i=0; i<4; ++i)
  {
    int dx=0, dy=0;
    switch (dirs[i])
    {
      case NORTH: dy = -1; break;
      case SOUTH: dy = 1; break;
      case EAST: dx = 1; break;
      case WEST: dx = -1; break;
    }
    int x2 = x + (dx<<1);
    int y2 = y + (dy<<1);
    if (IsInBounds(x2,y2))
    {
      if (grid[ XYToIndex(x2,y2) ] == '#')
      {
	grid[ XYToIndex(x2-dx,y2-dy) ] = ' ';
	Visit(x2,y2);
      }
    }
  }
}


string Gen::PrintGrid()
{
  string line =  "";
  for (int y=0; y<GRID_HEIGHT; ++y)
  {
    for (int x=0; x<GRID_WIDTH; ++x)
    {
      line += grid[XYToIndex(x,y)];
    }
    line +=  "\n";
  }
  return line;
}
void Gen::CreateMaze(string filename){
  srand(time(0));
  ResetGrid();
  Visit(1,1);
  SetStart();
  SetFinish();
  SetItems();
  ofstream fout;
  fout.open(filename);
  fout << PrintGrid();
  fout.close();
}

void Gen::SetStart(){
  for (int y=0; y<GRID_HEIGHT; ++y)
  {
    for (int x=0; x<GRID_WIDTH; ++x)
    {
      if(grid[XYToIndex(x,y)] != '#'){
	grid[XYToIndex(x,y)]= 's';
	return;
      }
    }
  }
  return;
}

void Gen::SetFinish(){
  for (int y=0; y<GRID_HEIGHT; ++y)
  {
    for (int x=0; x<GRID_WIDTH; ++x)
    {
      if(grid[XYToIndex(x,y)] != '#' and x > (GRID_WIDTH/2)and y > (GRID_HEIGHT/2)){
	grid[XYToIndex(x,y)] = 'f';
	return;
      }
    }
  }
  return;
}

void Gen::SetItems(){
  int count = 0;
  for (int y=0; y<GRID_HEIGHT; ++y)
  {
    for (int x=0; x<GRID_WIDTH; ++x)
    {
      ++count;
      if(count % 13 == 0 and grid[XYToIndex(x,y)] != 's' and grid[XYToIndex(x,y)] != 'f' and grid[XYToIndex(x,y)] != '#'){
	grid[XYToIndex(x,y)]= '$';

      }else if(count % 71 == 0 and grid[XYToIndex(x,y)] != 's' and grid[XYToIndex(x,y)] != 'f' and grid[XYToIndex(x,y)] != '#'){
	grid[XYToIndex(x,y)]= '^';
      }
    }
  }
}

