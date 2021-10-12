#pragma once
#include "../Game/GameObj.h"

enum type{TERRAIN, WATER};
class Tile {
    type type;
public:
    GameObj* content;
    void SetType(enum type type);
    enum type GetType();
    Tile(enum type type);
    bool walkable;
};
