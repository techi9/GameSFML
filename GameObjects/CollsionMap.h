#ifndef COLLSIONMAP_H
#define COLLSIONMAP_H

#include "../Field/Field.h"

class CollsionMap {
    bool** colmap;
    Field *field;
    int tileSize;
public:
    CollsionMap(Field& field, int tileSize);

    ~CollsionMap();
};


#endif  //COLLSIONMAP_H
