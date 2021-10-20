#pragma once
#include "string"
using namespace std;
class GameObj{
public:
    virtual string Render() = 0; // TODO: move it to ObjView or something
};
