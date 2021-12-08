
#ifndef GAMESFML_HYPERSTONE_H
#define GAMESFML_HYPERSTONE_H

#include "../Item.h"
#include "../../Entity.h"


class Hyperstone : public Item {
    using Item::Item;
    void interact(Entity &ent) override;
};


#endif //GAMESFML_HYPERSTONE_H
