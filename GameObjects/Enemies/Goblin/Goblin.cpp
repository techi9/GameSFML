#include "Goblin.h"

Goblin::Goblin(int x, int y) {
    health = 20;
    maxSpeed = 0.2;
    damage = 5;
    attackRadius = 30;
    attackSpeed = 1;
    setPosition(x, y);
}
