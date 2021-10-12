#pragma once

#include "Tile.h"
#include "string"
#include "memory"

using namespace std;

class Field {
    void CreatePuddle(int min_size, int max_size);

    void CreateEntranceAndExit();

    void CreateTiles(int w, int h);

    void CreateTiles();

    void DeleteTiles();

    friend class FieldView;

    template<typename T>
    bool CheckAround(int x, int y, int r = 1) {
        for (int i = -r; i < r + 1; i++) {
            for (int j = -r; j < r + 1; j++) {
                if (!(x + i < 0 || y + j < 0 || x + i >= width || y + j >= height)) //check x y
                    if (dynamic_cast<T *>(Tiles[x + i][y + j]->content))
                        return true;
            }
        }
        return false;
    };

    Tile ***Tiles;
    int width, height;
public:
    Field(int w, int h);
    bool Init();
    Field(Field &other);

    Field(Field &&other) noexcept;

    Field &operator=(Field &other);

    Field &operator=(Field &&other) noexcept;

    ~Field();

};



