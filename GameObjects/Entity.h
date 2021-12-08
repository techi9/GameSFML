
#ifndef GAMESFML_ENTITY_H
#define GAMESFML_ENTITY_H

#include <utility>
#include "GameObj.h"

class Entity : public GameObj{
public:
    int getHealth() const;

    void setHealth(int health);

    int getDamage() const;

    void setDamage(int damage);

    std::pair<float, float> getSpeed();

    void setSpeed(float x, float y);

    float getAttackRadius() const;

    void setAttackRadius(float attackRadius);

    void move();

protected:
    float health = 1;
    float damage = 0;
    float attackRadius = 0;
    float attackSpeed = 0;
public:
    float getAttackSpeed() const;

    void setAttackSpeed(float attackSpeed);

protected:
    float maxSpeed = 1;

private:
    std::pair<float, float> speed;
    unsigned int timeAttacked = 0;
    bool wantsAttack = false;
    bool wantsPickUp = false;
public:
    bool isWantsPickUp();

    void setWantsPickUp(bool wantsPickUp);

private:
    bool dead = false;
public:
    Entity() = default;

    bool checkAttack();

    void attack();

    virtual bool attack(Entity& ent);

    void pickUp();


};


#endif //GAMESFML_ENTITY_H
