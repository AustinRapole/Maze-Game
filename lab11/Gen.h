#ifndef GEN__H
#define GEN__H

#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

class Gen{
  public:
        void CreateMaze(string filename);
  private:
    	int XYToIndex(int x, int y);
        int IsInBounds(int x, int y);
	void Visit(int x, int y);
	string PrintGrid();
	void ResetGrid();
	void SetStart();
	void SetFinish();
	void SetItems();
};

#endif
