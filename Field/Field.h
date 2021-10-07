#pragma once
#include "Tile.h"
#include "string"
#include "memory"
using namespace std;

class Field {

public:
    Tile*** Tiles;
    int width, height;
    Field(int w, int h);
    ~Field();
};



