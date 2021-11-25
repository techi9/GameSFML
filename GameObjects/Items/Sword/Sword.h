//
// Created by tucha on 11/25/2021.
//

#ifndef GAMESFML_SWORD_H
#define GAMESFML_SWORD_H

#include "../../Item.h"
#include "../../Entity.h"


class Sword : public Item {
    void interact(Entity &ent);
};


#endif //GAMESFML_SWORD_H
