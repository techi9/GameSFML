#ifndef GAMESFML_HEALPOTION_H
#define GAMESFML_HEALPOTION_H

#include "../../Item.h"
#include "../../Entity.h"

class HealPotion : public Item{
    void interact(Entity &ent);
};


#endif //GAMESFML_HEALPOTION_H
