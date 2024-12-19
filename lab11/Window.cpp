#include "Window.h"

int Window::centerText(int w,string str){
  return (w-str.size())/2;
}

void Window::draw(Graphics* g){
  g->clearScreen();
  int w = g->getWidth();
  g->setAttributes("YELLOW:BLINK");
  g->drawString(centerText(w, "hello."),10,"hello.");
  g->setAttributes("WHITE");
  g->drawString(centerText(w, "[q] quit"),15, "[q] quit");
  g->drawString(centerText(w, "[a] advance"),16, "[a] advance");
  g->drawString(centerText(w, "[s] shop"),17, "[s] shop");

}

Window* Window::keyPressed(char c){
  if(c == 'q' || c == 'Q'){
    return NULL;
  }else if(c == 'a' || c == 'A'){
    return next;
  }else if(c == 's' || c == 'S'){
    return shop;
  }
  return this;
}
