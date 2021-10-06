#pragma once
#include "FieldView.h"
#include "string"
#include "memory"
using namespace std;

class Field {
    FieldView fv(string path_to_textures);
    //TODO: create 2d array of tiles using unique pointers
public:
    Field(int w, int h, string path_to_textures); //TODO: pass window here
};



