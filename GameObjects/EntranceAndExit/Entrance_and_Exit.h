#pragma once
#include "../GameObj.h"
class Entrance : public GameObj {
public:
    Entrance();
    string ObjType();
};

class Exit : public GameObj {
public:
    Exit();
    string ObjType();
};
