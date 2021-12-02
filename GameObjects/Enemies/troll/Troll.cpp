//
// Created by tucha on 11/18/2021.
//

#include "Troll.h"

Troll::Troll(int x, int y) {
    health = 50;
    maxSpeed = 0.3;
    damage = 30;
    attackRadius = 30;
    attackSpeed = 1;
    setPosition(x, y);
}

