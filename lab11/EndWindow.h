#ifndef ENDWINDOW__H
#define ENDWINDOW__H

#include "Window.h"
#include <vector>
#include <fstream>

using namespace std;

class EndWindow: public Window{
	public: 
	  EndWindow(string filename);
	  void draw(Graphics* g);
	  Window* keyPressed(char ch);

	private:
	  vector<string> data;
};
#endif
