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
#include "../GameObjects/Items/HealPotion/HealPotion.h"
#include "../GameObjects/Items/Sword/Sword.h"
#include "../GameObjects/Items/Hyperstone/Hyperstone.h"

class Game {
public:
    Game(int w, int h);
    ~Game();
    void CreateEntity(Entity *ent);

    void addController(Controller *cont);
    void CreateItem(Item *item);

private:
    int w, h;
    Field *field;
    FieldView *fview;
    CollsionMap *colMap;
    vector<Entity*> EntitiesList;
    vector<Item*> ItemList;

    vector<Controller*> Controllers;
    sf::Font font;
    ObjectView *objectView;
    void UpdateEntities();

    template<typename T>
    vector<T*> findNearObj(Entity &ent, float radius, vector<T*> &EntitiesList) {
        float xt = 0, yt = 0;
        vector<T*> foundEntities;
        for(auto &entity : EntitiesList){
            //x,y  x1,y1  x1-x, y1-y sqr(x1,y1)<=radius
            xt = entity->getPosition().first - ent.getPosition().first ;
            yt = entity->getPosition().second - ent.getPosition().second;
            if((xt*xt + yt*yt <= radius*radius) && (ent.getPosition().first != entity->getPosition().first && ent.getPosition().second != entity->getPosition().second)){
                foundEntities.push_back(entity);
            }
        }
        return foundEntities;
    }



    void RunLoop();
    sf::RenderWindow* window;
    void performAttacks();

};

