//
// Created by tucha on 11/25/2021.
//

#include "HealPotion.h"

void HealPotion::interact(Entity &ent) {
    ent.setHealth(ent.getHealth() + 50);
}
