#ifndef SHOPWINDOW__H
#define SHOPWINDOW__H

#include "Window.h"
#include "Explorer.h"
#include "Maze.h"
#include <algorithm>

class ShopWindow: public Window{
  public:
    ShopWindow(Explorer* e, Maze* m);
    void draw(Graphics* g);
    Window* keyPressed(char c);
    Window* game;
    Window* shop;
  private:
    Explorer* explorer;
    Maze* maze;

};

#endif
