
#include "Game.h"
#include "../Field/FieldView.h"
#include <stdlib.h>
#include <time.h>

Game::Game(int w, int h){
    srand (time(NULL));
    field = new Field(w, h);
    fview = new FieldView(field, "../Field/TileSet");
    fview->DrawField();
    system("pause");
}

