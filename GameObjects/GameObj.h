#pragma once
#include "string"
using namespace std;

class GameObj{
protected:
    std::pair<float, float> position;
    bool dead = false;
public:

    bool isDead() const;

    virtual bool attack(GameObj& o){return false;};

    virtual void die();

    std::pair<float, float> getPosition();

    void setPosition(float x, float y);

    virtual string ObjType(){};
};
