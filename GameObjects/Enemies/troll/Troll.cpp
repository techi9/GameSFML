//
// Created by tucha on 11/18/2021.
//

#include "Troll.h"

Troll::Troll(int x, int y) {
    health = 50;
    maxSpeed = 0.3;
    damage = 1;
    attackRadius = 30;
    attackSpeed = 0.5;
    setPosition(x, y);
}
