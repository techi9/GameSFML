#include "GameObj.h"

std::pair<float, float> GameObj::getPosition() {
    return position;
}

void GameObj::setPosition(float x, float y) {

    position = std::make_pair(x, y);
}

void GameObj::die() {
    dead = true;
}

bool GameObj::isDead() const {
    return dead;
}

