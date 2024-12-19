#include "EndWindow.h"

EndWindow:: EndWindow(string filename){
	ifstream fin;
	fin.open(filename);
	string line = "";
	while(getline(fin,line)){
	  data.push_back(line);
	}
	fin.close();

}
void EndWindow::draw(Graphics* g){
	g->clearScreen();
	int h = g->getHeight();
	int w = g->getWidth();
	int startx = (w-data[0].size())/2;
	int starty = (h-data.size())/2;
	g->setAttributes("RED");
	for(int i = 0; i < data.size(); ++i){
	g->drawString(startx,starty + i, data[i]);
	}
  	g->drawString(centerText(w, "Press any button to exit"),starty + 25, "Press any button to exit");
	

}

Window* EndWindow:: keyPressed(char ch){
  return next;
}
