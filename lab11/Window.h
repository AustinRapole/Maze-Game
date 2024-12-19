#ifndef WINDOW__H
#define WINDOW__H

#include "Drawable.h"

class Window: public Drawable{
	public:
		virtual void draw(Graphics* g);
		virtual Window* keyPressed(char c);
		int centerText(int w, string txt);
		Window* next = NULL;
		Window* shop = NULL;


};


#endif
