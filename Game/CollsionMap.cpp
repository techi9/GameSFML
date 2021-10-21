#include <iostream>
#include "CollsionMap.h"

CollsionMap::CollsionMap(Field &field, int tileSize) {
    cout << "Creating collision map" << std::endl;//TODO: move to logger
    this->field = &field;
    this->tileSize = tileSize;
    w = field.getWidth() * tileSize;
    h = field.getHeight() * tileSize;
    colmap = new bool *[field.getWidth() * tileSize];
    for (int i = 0; i < field.getWidth() * tileSize; i++) {
        colmap[i] = new bool[field.getHeight() * tileSize];
    }
    for (int tile_y = 0; tile_y < field.getHeight(); tile_y++) {
        for (int tile_x = 0; tile_x < field.getWidth(); tile_x++) {
            cout << field.getTiles()[tile_x][tile_y]->isWalkable();
            for (int x = tile_x * tileSize; x < tile_x * tileSize + tileSize; x++) {
                for (int y = tile_y * tileSize; y < tile_y * tileSize + tileSize; y++) {
                    colmap[x][y] = field.getTiles()[tile_x][tile_y]->isWalkable();
//                    if (!colmap[x][y])
//                        cout<<tile_x<<" "<<tile_y;
                }
            }
        }
        cout << "\n";
    }
    cout << "Creating finished";
}

CollsionMap::~CollsionMap() {
    for (int i = 0; i < field->getWidth() * tileSize; i++) {
        delete[] colmap[i];
    }
    delete[] colmap;
}

bool CollsionMap::at(int x, int y) {
    if (x < w && x >= 0 && y < h && y >= 0) {
        return colmap[x][y];
    } else {
        return false;
    }
}

