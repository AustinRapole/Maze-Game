#ifndef DRAWABLE__H
#define DRAWABLE__H

#include <string>
#include "Graphics.h"
using namespace std;

class Drawable{
public:
    virtual void draw(Graphics* window) = 0;
};

#endif

