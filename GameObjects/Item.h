#ifndef GAMESFML_ITEM_H
#define GAMESFML_ITEM_H
#include "GameObj.h"
#include "Entity.h"

class Item : public GameObj{
public:
    Item(float x, float y);
    virtual void interact(Entity &ent){};
};


#endif //GAMESFML_ITEM_H
