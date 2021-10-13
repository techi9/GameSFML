#pragma once
#include "../Game/GameObj.h"



class Tile {
public:
    enum type{TERRAIN, WATER};
    GameObj* content;
    void SetType(enum type type);
    enum type GetType();
    Tile(enum type type);
    bool walkable;
private:
    friend class FieldView;
    type type;
    //friend class FieldView;
};
