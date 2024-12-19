#include "AWindow.h"

void AWindow::draw(Graphics* g){
  g->clearScreen();
  int width = g->getWidth();
  int height = g->getHeight()/2;
  string s = "audrey";
  width -= s.size();
  width /= 2;
  g->setAttributes("MAGENTA:BOLD");
  g->drawString(width,height,s);
}

Window* AWindow::keyPressed(char ch){
  return next;
}
