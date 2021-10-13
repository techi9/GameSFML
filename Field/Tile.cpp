#include "Tile.h"

void Tile::SetType(enum Tile::type type){
    this->type = type;
};
enum Tile::type Tile::GetType(){
    return type;
};



Tile::Tile(enum type type){
    this->type = type;
    if (type == WATER)
        walkable = false;
    else if (type == TERRAIN)
        walkable = true;
};
