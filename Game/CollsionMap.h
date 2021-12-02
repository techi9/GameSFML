#ifndef COLLSIONMAP_H
#define COLLSIONMAP_H

#include "../Field/Field.h"

class CollsionMap {
    bool** colmap;
    Field *field;
    int tileSize;
    int w, h;
public:
    CollsionMap(Field& field, int tileSize);
    bool at(int x, int y);
    ~CollsionMap();

};


#endif  //COLLSIONMAP_H
