#ifndef GAMESFML_HEALPOTION_H
#define GAMESFML_HEALPOTION_H

#include "../../Item.h"
#include "../../Entity.h"

class HealPotion : public Item{
    using Item::Item;
    void interact(Entity &ent) override;
};


#endif //GAMESFML_HEALPOTION_H
