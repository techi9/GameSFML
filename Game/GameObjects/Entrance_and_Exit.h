#pragma once
#include "../GameObj.h"
class Entrance : public GameObj {
public:
    Entrance();
    string Render();
};

class Exit : public GameObj {
public:
    Exit();
    string Render();
};
