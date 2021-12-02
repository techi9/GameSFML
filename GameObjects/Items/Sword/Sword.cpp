//
// Created by tucha on 11/25/2021.
//

#include "Sword.h"

void Sword::interact(Entity &ent) {
    ent.setDamage(ent.getDamage() + 20);
}
