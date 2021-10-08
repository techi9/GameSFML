#pragma once
#include "Field.h"
#include "string"
using namespace std;

class Field; //TODO: fix this (why is it even here?)

class FieldView {
    bool loadTextures(string path_to_folder); //TODO: create all logic for drawing
    Field *field;
public:
    FieldView(Field* field, string path_to_tilemap);
    void DrawField();
};
