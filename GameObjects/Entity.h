#ifndef GAMESFML_ENTITY_H
#define GAMESFML_ENTITY_H


class Entity {
private:

protected:
    int health;
    int damage = 0;
public:
    Entity();
    virtual bool attacked(int damage);
    virtual bool attack(int damage);
    virtual void die();

};


#endif //GAMESFML_ENTITY_H
