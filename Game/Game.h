#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include "../Field/Field.h"
#include "../Field/FieldView.h"
#include "CollsionMap.h"
#include "../GameObjects/Entity.h"

class Game {
public:
    Game(int w, int h);
    ~Game();
private:
    int w, h;
    Field *field;
    FieldView *fview;
    CollsionMap *colMap;
    vector<Entity> EntitiesList;
    void CreateEntity(Entity ent);


    void RunLoop();
    sf::RenderWindow* window;
};

