#include "Console.h"

Console::Console(){
    update = true;
	canvas = NULL;
}

void Console::setDrawable(Drawable* c){
	canvas = c;
}

Drawable* Console::getDrawable(){
	return canvas;
}

bool Console::getChar(char& ch){
    int c = wgetch(window);
	if(isprint(c)){
		ch = c;
		update = true;		
		return true;
	}
	return false;
}


bool Console::getLine(string& line){
    //if(window == NULL || canvas == nullptr)
    //    return false;
    
    int c = wgetch(window);
    update = true;
    if(c == 8 || c == 127){
        if(buffer.size() > 0){
            buffer.erase(buffer.size()-1);
        }
    }else if(c == '\n' || c == '\r'){
        line = buffer;
        buffer = "";
        return true;
    }else if(iscntrl(c)){
        
    }else if(isprint(c)){
        buffer += c;
    }else{
        update = false;
    }
    line = buffer;
    return false;
}

void Console::redraw(){
	if(canvas){
		canvas->draw(this);
	}
	update = false;
}

int Console::getWidth(){
    int height,width;
    getmaxyx(window,height,width);
    return width;
}

int Console::getHeight(){
    int height,width;
    getmaxyx(window,height,width);
    return height;
}

void Console::clearScreen(){
    clear();
}

void Console::drawString(int x,int y,string str){
	update = true;
    mvwaddstr(window,y,x,str.c_str());
}

void Console::setAttributes(string attr){
	stringstream sin(attr);
    string token;
	
	set<string> newAttrs;
	vector<string> newColor;

    while (getline(sin, token, ':')){
		transform(token.begin(), token.end(), token.begin(), ::toupper);
		if(attributes.find(token) != attributes.end()){
			newAttrs.insert(token);
		}else if(colors.find(token) != colors.end()){
			newColor.push_back(token);
		}
	}

	int colorChange = color;
	if(newColor.size() >= 2){
		colorChange = colors[newColor[0]+newColor[1]];
	}else if(newColor.size() == 1){
		colorChange = colors[newColor[0]];
	}

    if(color != colorChange){
        attroff(COLOR_PAIR(color));
        color = colorChange;
        attron(COLOR_PAIR(color));
    }

	for(auto key: attrs){
		if(newAttrs.find(key) == newAttrs.end()){
			attroff(attributes[key]);
		}
	}

    for(auto key: newAttrs){
        if(attrs.find(key) == attrs.end()){
            attron(attributes[key]);
        }
    }


	attrs = newAttrs;
	if(attrs.size() == 0){
		attron(A_NORMAL);
	}	

}


void Console::initialize(){
    window = initscr();
    int height,width;
    getmaxyx(window,height,width);
    noecho();
    nodelay(window,true);
    curs_set(0);
   
    attributes["BLINK"] = A_BLINK;
    attributes["BOLD"] = A_BOLD;
	attributes["REVERSE"] = A_REVERSE;
    attributes["ITALIC"] = A_ITALIC;
    attributes["UNDERLINE"] = A_UNDERLINE;
	attributes["STANDOUT"] = A_STANDOUT;
    attributes["DIM"] = A_DIM;
    attributes["INVIS"] = A_INVIS;

	vector<string> colorNames = {"BLACK","RED","GREEN","BLUE","YELLOW","MAGENTA","CYAN","WHITE"};
    vector<int> colorCodes = {COLOR_BLACK,COLOR_RED,COLOR_GREEN,COLOR_BLUE,COLOR_YELLOW
		,COLOR_MAGENTA,COLOR_CYAN,COLOR_WHITE};

	if(has_colors()){
		start_color();
		use_default_colors();
		int index = 1;
		for(int i =0; i < colorNames.size(); ++i){
			string fg = colorNames[i];
			colors[fg] = index;
            init_pair(index,colorCodes[i],-1);
			index += 1;
			for(int j =0; j < colorNames.size(); ++j){
				string bg = colorNames[j];
				colors[fg+bg] = index;
				init_pair(index,colorCodes[i],colorCodes[j]); 
				index += 1;
			}
		}
		color = 0;
	}	

	update = true;
    refresh();

}

void Console::shutdown(){
    delwin(window);
    endwin();
	update = true;
    refresh();
}


