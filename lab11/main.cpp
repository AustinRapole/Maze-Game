#include "Console.h"
#include "Window.h"
#include "GameWindow.h"
#include "ShopWindow.h"
#include "EndWindow.h"
#include "Gen.h"

using namespace std;


int main(){
	srand(time(0));
  	Explorer explorer;
	Maze maze;
	Gen test;
	test.CreateMaze("generated_test_maze");
	maze.load("generated_test_maze");

	vector<Coordinate> locs = maze.locationOf('s');
	if(locs.empty()){
	  explorer.location = Coordinate(0,0);
	}else{
	  explorer.location = locs[rand()%locs.size()];
	}

	Window* mainWindow = new Window();
	Window* reset = new Window();
	GameWindow* gameWindow = new GameWindow(& explorer, &maze);
	ShopWindow* shopWindow = new ShopWindow(& explorer, &maze);
	EndWindow* endWindow = new EndWindow("win.txt");
	EndWindow* loseWindow = new EndWindow("lose.txt");
	mainWindow->next = gameWindow;
	mainWindow->shop = shopWindow;
	gameWindow->win = endWindow;
	gameWindow->lose = loseWindow;
	shopWindow->game = gameWindow;
	gameWindow->menu = mainWindow;
	shopWindow->shop = shopWindow;
	
	Window* currentWindow = mainWindow;

	Console console;
	console.setDrawable(mainWindow);

	console.initialize();

	console.redraw();

	bool running = true;
	while(running){
		char ch = '?';
		if(console.getChar(ch)){
			currentWindow = currentWindow->keyPressed(ch);
			if(!currentWindow){
				running = false;
			}else{
			  if(currentWindow == reset){
			    currentWindow = mainWindow;
			  }
				console.setDrawable(currentWindow);
				console.redraw();
			}
		}
	}
	
	console.shutdown();
	return 0;
}
