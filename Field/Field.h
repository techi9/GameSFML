#pragma once
#include "Tile.h"
#include "string"
#include "memory"
#include "FieldView.h"
using namespace std;

class Field {
    void CreatePuddle(int min_size, int max_size);
    void CreateEntranceAndExit();
    void CreateTiles(int w, int  h);
    void CreateTiles();
    void DeleteTiles();
    friend class FieldView;

template <typename T>
    bool CheckAround(int x, int y){
        if(x==width-1)
            x--;
        else if(x==0)
            x++;
        if(y==height-1)
            y--;
        else if(y==0)
            y++;
    return dynamic_cast<T*>(Tiles[x][y]->content) ||
         dynamic_cast<T*>(Tiles[x+1][y]->content) ||
         dynamic_cast<T*>(Tiles[x-1][y]->content) ||
         dynamic_cast<T*>(Tiles[x][y+1]->content) ||
         dynamic_cast<T*>(Tiles[x][y-1]->content) ||
         dynamic_cast<T*>(Tiles[x+1][y+1]->content) ||
         dynamic_cast<T*>(Tiles[x-1][y+1]->content) ||
         dynamic_cast<T*>(Tiles[x-1][y-1]->content) ||
         dynamic_cast<T*>(Tiles[x+1][y-1]->content);
    };

    Tile*** Tiles;
    int width, height;
public:
    Field(int w, int h);
    Field(Field& other);
    Field(Field&& other);
    Field& operator=(Field& other);
    Field& operator=(Field&& other);
    ~Field();



};



