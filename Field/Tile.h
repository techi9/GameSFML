#pragma once
#include "../GameObjects/GameObj.h"


class Tile {
public:
    enum type{TERRAIN, WATER};
    Tile(enum type type);
    void SetType(enum type type);
    enum type GetType();
    bool isWalkable() const;
private:
    GameObj* content;
    bool walkable;
    type type;
    friend class Field;
    friend class FieldView;
};

