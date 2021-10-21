#include "Tile.h"

void Tile::SetType(enum Tile::type type){
    this->type = type;
    if (type == WATER)
        walkable = false;
    else if (type == TERRAIN)
        walkable = true;
};
enum Tile::type Tile::GetType(){
    return type;
};

bool Tile::isWalkable() const {
    return walkable;
}

Tile::Tile(enum type type){
    SetType(type);
};
