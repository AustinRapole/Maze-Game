#ifndef AWINDOW__H
#define AWINDOW__H

#include "Window.h"

class AWindow: public Window{
  public:
    void draw(Graphics* g);
    Window* keyPressed(char c);

};

#endif
