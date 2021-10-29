//
// Created by tucha on 29.10.2021.
//

#include "Turret.h"

Turret::Turret(int x, int y) {
    health = 250;
    damage = 5;
    maxSpeed = 0;
    setPosition(x, y);
}
