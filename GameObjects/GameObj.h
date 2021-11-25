#pragma once
#include "string"
using namespace std;

class GameObj{
protected:
    std::pair<float, float> position;
public:
    std::pair<float, float> getPosition();

    void setPosition(float x, float y);

    virtual string ObjType(){};
};
