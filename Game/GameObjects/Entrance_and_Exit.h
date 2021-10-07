#pragma once
#include "../GameObj.h"
class Entrance : public GameObj {

    string Render();
public:
    Entrance();
};

class Exit : public GameObj {

    string Render();
public:
    Exit();
};
