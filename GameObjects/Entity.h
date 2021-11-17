
#ifndef GAMESFML_ENTITY_H
#define GAMESFML_ENTITY_H

#include <utility>

class Entity {
public:
    int getHealth() const;

    void setHealth(int health);

    int getDamage() const;

    void setDamage(int damage);

    std::pair<float, float> getSpeed();

    std::pair<float, float> getPosition();

    void setSpeed(float x, float y);

    void setPosition(float x, float y);

    void move();

protected:
    int health;
    int damage = 0;
    float attackRadius;
    int attackSpeed;
public:
    float getAttackRadius() const;

    void setAttackRadius(float attackRadius);

protected:
    std::pair<float, float> speed;
    float maxSpeed = 1;
    std::pair<float, float> position;
    bool wantsAttack = false;
public:
    Entity() = default;

    bool checkAttack();

    virtual void attack();

    virtual bool attack(Entity& ent) {};

    virtual void die() {};

};


#endif //GAMESFML_ENTITY_H
