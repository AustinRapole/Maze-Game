#include "Explorer.h"

void Explorer:: save(string filename){
	ofstream fout;
	fout.open(filename);
	fout << coins << endl;
	fout << location.x << "\t" + location.y << endl;;
	fout << health << endl;
	fout << bomb;
	fout.close();
}

void Explorer::load(string filename){
	ifstream fin;
	fin.open(filename);
	fin >> coins;
	fin >> location.x;
	fin >> location.y;
	fin >> health;
	fin >> bomb;
	fin.close();
}

