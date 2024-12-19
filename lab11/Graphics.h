#ifndef GRAPHICS__H
#define GRAPHICS__H

#include <string>
using namespace std;

class Graphics{
public:
    
    virtual void drawString(int x,int y,string str) = 0;
    virtual int getWidth() = 0;
    virtual int getHeight() = 0;
    virtual void clearScreen() = 0;
    virtual void setAttributes(string attr) =0;
};

#endif

