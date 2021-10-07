#pragma once
#include "Field.h"
#include "Tile.h"
#include <stdlib.h>
#define MIN_PUDDLE_SIZE 2
#define MAX_PUDDLE_SIZE 5
Field::Field(int w, int h){
    width = w;
    height = h;
    //creating the Tilemap array
    Tiles = new Tile** [w];
    for (int i = 0; i < w; i++)
    {
        Tiles[i] = new Tile*[h];
    }

    for(int i = 0; i < w; i++)
    {
        for(int j = 0; j < h; j++)
        {
            Tiles[i][j] = new Tile(TERRAIN);
        }
    }

    int x_for_puddle = rand() % w;
    int y_for_puddle = rand() % h;
    int puddle_radius = MIN_PUDDLE_SIZE + rand() % (MAX_PUDDLE_SIZE - MIN_PUDDLE_SIZE);
    for (int i = -puddle_radius; i <=puddle_radius; i++)
    {
        for (int j = -puddle_radius; j <=puddle_radius; j++)
        {
            if (i*i + j*j <= puddle_radius*puddle_radius)
            {
                if(x_for_puddle+i < w && x_for_puddle+i >= 0 && y_for_puddle+j < w && y_for_puddle+j >= 0)
                Tiles[x_for_puddle+i][y_for_puddle+j]->SetType(WATER);
            }
        }
    }

}

Field::~Field(){
    for (int i = 0; i < width; i++)
    {
        delete [] Tiles[i];
    }
    delete [] Tiles;
}