#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include "../Field/Field.h"
#include "../Field/FieldView.h"
#include "CollsionMap.h"
#include "../GameObjects/Entity.h"
#include "../GameObjects/ObjectView.h"
#include "../GameObjects/Player/ControllerKeyboard.h"
#include "../GameObjects/Enemies/Turret/Turret.h"
#include "../GameObjects/Player/Player.h"
#include "../GameObjects/Enemies/EnemyController.h"
#include "../GameObjects/Enemies/troll/Troll.h"
#include "Controller.h"
#include "../GameObjects/Item.h"
#include "../GameObjects/Enemies/Goblin/Goblin.h"

class Game {
public:
    Game(int w, int h);
    ~Game();
    void CreateEntity(Entity *ent);
    void addController(Controller *cont);
    void CreateItem(Item item);

private:
    int w, h;
    Field *field;
    FieldView *fview;
    CollsionMap *colMap;
    vector<Entity*> EntitiesList;
    vector<Item> ItemList;

    vector<Controller*> Controllers;
    ObjectView *objectView;
    void UpdateEntities();


    void RunLoop();
    sf::RenderWindow* window;
    void performAttacks();

    vector<Entity*> findNearEntities(Entity &ent, float radius);
};

