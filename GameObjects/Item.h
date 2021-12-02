#ifndef GAMESFML_ITEM_H
#define GAMESFML_ITEM_H
#include "GameObj.h"
#include "Entity.h"

class Item : public GameObj{
public:
    Item(float x, float y);
    virtual void interact(Entity &ent){};
    bool ToDelete = false;
};


#endif //GAMESFML_ITEM_H
