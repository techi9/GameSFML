#pragma once
#include "../Field/Field.h"
#include "../Field/FieldView.h"

class Game {
    int w, h;
    Field *field;
    FieldView *fview;

public:
    Game(int w, int h);
};

