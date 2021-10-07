#pragma once
#include "../Game/GameObj.h"

enum type{TERRAIN, WATER};
class Tile {
    GameObj content;
    type type;
public:
    void SetType(enum type type);
    enum type getType();
    Tile(enum type type);
};
