#ifndef GAMEWINDOW__H
#define GAMEWINDOW__H

#include "Window.h"
#include "Explorer.h"
#include "Maze.h"
#include <algorithm>

class GameWindow: public Window{
  public:
    GameWindow(Explorer* e, Maze* m);
    void draw(Graphics* g);
    Window* keyPressed(char c);
    Window* win;
    Window* lose;
    Window* menu;
  private:
    Explorer* explorer;
    Maze* maze;

};

#endif
