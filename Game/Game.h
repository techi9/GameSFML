#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include "../Field/Field.h"
#include "../Field/FieldView.h"

class Game {
public:
    Game(int w, int h);
    ~Game();
private:
    int w, h;
    Field *field;
    FieldView *fview;

    void RunLoop();
    sf::RenderWindow* window;
};

