
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
    std::pair<float, float> speed;
    float maxSpeed = 1;
    std::pair<float, float> position;
public:
    Entity() = default;

    virtual bool attacked(int dmg) {};

    virtual bool attack(int dmg) {};

    virtual void die() {};

};


#endif //GAMESFML_ENTITY_H
