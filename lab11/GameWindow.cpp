#include "GameWindow.h"

GameWindow::GameWindow(Explorer* e, Maze* m){
  explorer = e;
  maze = m;
}

void GameWindow:: draw(Graphics* g){
  g->clearScreen();

  Coordinate center(g->getWidth(), g->getHeight());

  g->setAttributes("YELLOW");
  g->drawString(0,0,"Coins: " + to_string(explorer->coins));

  g->setAttributes("WHITE");
  g->drawString(0,1,"Health: " + to_string(explorer->health));
  g->drawString(0,2,"Bombs: " + to_string(explorer->bomb));

  center = center/2;
  g->setAttributes("WHITE");
  int radius = explorer->radius;
  vector<string> data = maze->getData(explorer->location, radius);
  for(int i = 0; i < data.size(); ++i){
    g->drawString(center.x -radius, center.y-radius+i,data[i]);
  }

  vector<Coordinate> coins = maze->locationOf('$');
  g->setAttributes("YELLOW");
  for(Coordinate c: coins){
    Coordinate d = c-explorer->location;
    if(d.x <= radius and d.y <=radius and d.x >= -radius and d.y >= -radius){
      g->drawString(center.x+d.x,center.y+d.y,"$");
    }
  }

  vector<Coordinate> spikes = maze->locationOf('^');
  g->setAttributes("RED");
  for(Coordinate s: spikes){
    Coordinate d = s-explorer->location;
    if(d.x <= radius and d.y <=radius and d.x >= -radius and d.y >= -radius){
      g->drawString(center.x+d.x,center.y+d.y, "^");
    }
  }


  g->setAttributes("MAGENTA");
  g->drawString(center.x,center.y, "@");

}
//void GameWindow:: handle location

Window* GameWindow::keyPressed(char ch){
  int brad = explorer->brad;
  Coordinate a = Coordinate(0,1);
  Coordinate b = Coordinate(0,-1);
  Coordinate c = Coordinate(-1,0);
  Coordinate d = Coordinate(1,0);
  Coordinate e = Coordinate(1,1);
  Coordinate f = Coordinate(1,-1);
  Coordinate g = Coordinate(1,1);
  Coordinate h = Coordinate(-1,1);
  Coordinate i = Coordinate(0,brad);
  Coordinate j = Coordinate(0,-brad);
  Coordinate k = Coordinate(-brad,0);
  Coordinate l = Coordinate(brad,0);
  Coordinate m = Coordinate(brad,brad);
  Coordinate n = Coordinate(brad,-brad);
  Coordinate o = Coordinate(brad,brad);
  Coordinate p = Coordinate(-brad,brad);

  Coordinate move;
  if(ch == 's'){
    move = Coordinate(0,1);
  }else if(ch == 'w'){
    move = Coordinate(0,-1);
  }else if(ch == 'a'){
    move = Coordinate(-1,0);
  }else if(ch == 'd'){
    move = Coordinate(1,0);
  }else if( ch == '~'){
    maze->save("maze_save");
    explorer->save("ex_save");
  }else if(ch == '`'){
    maze->load("maze_save");
    explorer->load("ex_save");
  }else if(ch == 'p'){
    return menu;
  }else if(ch == 'b'){
    if(explorer->bomb > 0){
      //dont judge it works ok
      explorer->bomb -=1;
      maze->setSymbol(explorer->location -a, ' ');
      maze->setSymbol(explorer->location +a, ' ');
      maze->setSymbol(explorer->location -b, ' ');
      maze->setSymbol(explorer->location +b, ' ');
      maze->setSymbol(explorer->location -c, ' ');
      maze->setSymbol(explorer->location +c, ' ');
      maze->setSymbol(explorer->location -d, ' ');
      maze->setSymbol(explorer->location +d, ' ');
      maze->setSymbol(explorer->location -e, ' ');
      maze->setSymbol(explorer->location +e, ' ');
      maze->setSymbol(explorer->location -f, ' ');
      maze->setSymbol(explorer->location +f, ' ');
      maze->setSymbol(explorer->location -g, ' ');
      maze->setSymbol(explorer->location +g, ' ');
      maze->setSymbol(explorer->location -h, ' ');
      maze->setSymbol(explorer->location +h, ' ');
      maze->setSymbol(explorer->location -i, ' ');
      maze->setSymbol(explorer->location +i, ' ');
      maze->setSymbol(explorer->location -j, ' ');
      maze->setSymbol(explorer->location +j, ' ');
      maze->setSymbol(explorer->location -k, ' ');
      maze->setSymbol(explorer->location +k, ' ');
      maze->setSymbol(explorer->location -l, ' ');
      maze->setSymbol(explorer->location +l, ' ');
      maze->setSymbol(explorer->location -m, ' ');
      maze->setSymbol(explorer->location +m, ' ');
      maze->setSymbol(explorer->location -n, ' ');
      maze->setSymbol(explorer->location +n, ' ');
      maze->setSymbol(explorer->location -o, ' ');
      maze->setSymbol(explorer->location +o, ' ');
      maze->setSymbol(explorer->location -p, ' ');
      maze->setSymbol(explorer->location +p, ' ');
    }

  }
  if(maze->isValid(explorer->location + move)){
    explorer->location = explorer->location + move;
  }else{
    explorer->location = explorer->location;
  }

  //if valid location
  char value = maze->getSymbol(explorer->location);
  if(value == 'f'){
    return win;
  }else if(value == '$'){
    explorer->coins +=1;
    maze->setSymbol(explorer->location, ' ');
  }else if( value == '^'){
    explorer->health -=1;
    if(explorer->health == 0){
      return lose;
    }
    maze->setSymbol(explorer->location, ' ');
  };

  /*  vector<Coordinate> finish = maze->locationOf('f');
      if(find(finish.begin(), finish.end(),explorer->location != finish.end())){
      return NULL;
      }
   */
  return this;
}
