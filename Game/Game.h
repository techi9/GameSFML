#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include "../Field/Field.h"
#include "../Field/FieldView.h"
#include "CollsionMap.h"
#include "../GameObjects/Entity.h"
#include "../GameObjects/ObjectView.h"
#include "../GameObjects/Player/ControllerKeyboard.h"

class Game {
public:
    Game(int w, int h);
    ~Game();
    void CreateEntity(Entity *ent);
    void CreateObj(GameObj obj);

private:
    int w, h;
    Field *field;
    FieldView *fview;
    CollsionMap *colMap;
    vector<Entity*> EntitiesList;
    ObjectView *objectView;
    void UpdateEntities();
    ControllerKeyboard* playerController;


    void RunLoop();
    sf::RenderWindow* window;
    void performAttacks();

    vector<Entity*> findNearEntities(Entity &ent, float radius);
};

