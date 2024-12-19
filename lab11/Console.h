#ifndef CONSOLE__H
#define CONSOLE__H
#include <unistd.h>
#include <curses.h>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>
#include <vector>
#include "Graphics.h"
#include "Drawable.h"
using namespace std;


class Console: public Graphics{
public:
    Console();
    void initialize();
    void shutdown();
    
    bool getLine(string& line);
	bool getChar(char& ch);    

	void setDrawable(Drawable* d);
	Drawable* getDrawable();

    void drawString(int x,int y,string str);

	void setAttributes(string attr);

    int getWidth();
    int getHeight();
    
    void clearScreen();
	void redraw();    

private:
    WINDOW* window;
	bool update;
	Drawable* canvas;
	set<string> attrs;
	map<string,int> attributes;
	int color;
	map<string,int> colors;

    string buffer;
    
};

#endif
