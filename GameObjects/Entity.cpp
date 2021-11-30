#include "Entity.h"
#include "iostream"
#include "algorithm"
#include <time.h>

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



void Entity::move() {
    setPosition(position.first + speed.first, position.second + speed.second);
}

bool Entity::checkAttack() {
    if(wantsAttack) {
        wantsAttack = false;
        return true;
    }
    return false;
}

void Entity::attack() {
    unsigned int curTime = time(nullptr);

    if(curTime - timeAttacked > 1/attackSpeed){
        wantsAttack = true;
        timeAttacked = time(nullptr);
    }

}

float Entity::getAttackRadius() const {
    return attackRadius;
}

void Entity::setAttackRadius(float attackRadius) {
    this->attackRadius = attackRadius;
}

bool Entity::attack(Entity &ent) {
    ent.setHealth(ent.getHealth() - damage);
    if (ent.getHealth() <= 0){
        ent.die();
    }
    return true;
}

float Entity::getAttackSpeed() const {
    return attackSpeed;
}

void Entity::setAttackSpeed(float attackSpeed) {
    Entity::attackSpeed = attackSpeed;
}
