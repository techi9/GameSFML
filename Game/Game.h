#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include "../Field/Field.h"
#include "../Field/FieldView.h"
#include "../GameObjects/CollsionMap.h"

class Game {
public:
    Game(int w, int h);
    ~Game();
private:
    int w, h;
    Field *field;
    FieldView *fview;
    CollsionMap *colMap;

    void RunLoop();
    sf::RenderWindow* window;
};

