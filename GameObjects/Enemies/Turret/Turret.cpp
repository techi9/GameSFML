#include "Turret.h"

Turret::Turret(int x, int y) {
    health = 200;
    maxSpeed = 0;
    damage = 3;
    attackRadius = 100;
    attackSpeed = 0.33;
    setPosition(x, y);
}
