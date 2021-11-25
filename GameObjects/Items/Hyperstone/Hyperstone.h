
#ifndef GAMESFML_HYPERSTONE_H
#define GAMESFML_HYPERSTONE_H

#include "../../Item.h"
#include "../../Entity.h"


class Hyperstone : public Item {
    void interact(Entity &ent);
};


#endif //GAMESFML_HYPERSTONE_H
