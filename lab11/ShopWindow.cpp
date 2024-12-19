#include "Window.h"
#include "ShopWindow.h"

ShopWindow::ShopWindow(Explorer* e, Maze* m){
  explorer = e;
  maze = m;
}

void ShopWindow::draw(Graphics* g){
  g->clearScreen();
  int w = g->getWidth();

  g->setAttributes("YELLOW");
  g->drawString(0,0,"Coins: " + to_string(explorer->coins));
  g->setAttributes("WHITE");
  g->drawString(0,1,"Health: " + to_string(explorer->health));
  g->drawString(0,2,"Bombs: " + to_string(explorer->bomb));

  g->setAttributes("WHITE");
  g->drawString(centerText(w, "[f] flashlight: 15 coins"),15, "[f] flashlight: 15 coins");
  g->drawString(centerText(w, "[b] bomb: 5 coins"),17, "[b] bomb: 5 coins");
  g->drawString(centerText(w, "[h] heart: 5 coins"),19, "[h] heart: 5 coins");
  g->drawString(centerText(w, "[a] bigger bombs: 20 coins"),21, "[a] bigger bombs: 20 coins");
  g->drawString(centerText(w, "[r] return"),13, "[r] return");


}

Window* ShopWindow::keyPressed(char c){
  if(c == 'f' || c == 'F'){
    if(explorer->coins >= 15){
      explorer->radius +=4;
      explorer->coins -=15;
      return shop;
    }else{
      return shop;
    }
  }else if(c == 'b' || c == 'B'){
    if(explorer->coins >= 5){
      explorer->bomb +=1;
      explorer->coins -=5;
      return shop;
    }else{
      return shop;
    }
  }else if(c == 'a' || c == 'C'){
    if(explorer->coins >= 20){
      explorer ->brad +=1;
      explorer->coins -=20;
      return shop;
    }else{
      return shop;
    }
  }else if(c == 'h' || c == 'H'){
    if(explorer->coins >= 5){
      explorer->health +=1;
      explorer->coins -=5;
      return shop;
    }else{
      return shop;
    }
  }else if(c == 'r' || c == 'R'){
    return game;
  }else{
    return this;
  }
}



