#include "Entity.h"
#include "iostream"
#include "algorithm"

int Entity::getHealth() const {
    return health;
}

void Entity::setHealth(int health) {
    this->health = health;
}

int Entity::getDamage() const {
    return damage;
}

void Entity::setDamage(int damage) {
    this->damage = damage;
}

std::pair<float, float> Entity::getSpeed() {
    return speed;
}

std::pair<float, float> Entity::getPosition() {
    return position;
}

void Entity::setSpeed(float x, float y) { //and max speed check
    float finalSpeedX = 0;
    float finalSpeedY = 0;

    if (x > 0)
    {
        finalSpeedX = std::min(x, maxSpeed);
    }
    else if (x < 0)
    {
        finalSpeedX = std::max(x, -maxSpeed);
    }

    if (y > 0)
    {
        finalSpeedY = std::min(y, maxSpeed);
    }
    else if (y < 0)
    {
        finalSpeedY = std::max(y, -maxSpeed);
    }

    speed = std::make_pair(finalSpeedX, finalSpeedY);
//    if (finalSpeedX || finalSpeedY){
//        if (position.first == 500)
//        std::cout<<finalSpeedX<<"------------------------------ "<<speed.second<<'\n';
//    }
}

void Entity::setPosition(float x, float y) {

    position = std::make_pair(x, y);
}

void Entity::move() {
    setPosition(position.first + speed.first, position.second + speed.second);
}

bool Entity::checkAttack() {
    if(wantsAttack) {
        wantsAttack = false;
        return true;
    }
    else return false;
}

void Entity::attack() {//TODO: add attackspeed check

    wantsAttack = true;
}

float Entity::getAttackRadius() const {
    return attackRadius;
}

void Entity::setAttackRadius(float attackRadius) {
    Entity::attackRadius = attackRadius;
}

bool Entity::attack(Entity &ent) {
    ent.setHealth(ent.getHealth() - damage);
    return true;
}
