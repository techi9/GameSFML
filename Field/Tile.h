#pragma once
#include "../Game/GameObj.h"


class Tile {
public:
    enum type{TERRAIN, WATER};
    Tile(enum type type);
    void SetType(enum type type);
    enum type GetType();
private:
    GameObj* content;
    bool walkable;
    type type;
    friend class Field;
    friend class FieldView;
};
