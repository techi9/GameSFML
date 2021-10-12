#pragma once
#include "Field.h"
#include "Tile.h"
#include <stdlib.h>
#include "../Game/GameObjects/Entrance_and_Exit.h"
#define MIN_PUDDLE_SIZE 2
#define MAX_PUDDLE_SIZE 5
using namespace std;

Field::Field(int w, int h){
    width = w;
    height = h;
    //creating the Tilemap array
    CreateTiles(w, h);

    CreatePuddle(MIN_PUDDLE_SIZE, MAX_PUDDLE_SIZE);
    CreatePuddle(MIN_PUDDLE_SIZE, MAX_PUDDLE_SIZE);
    CreateEntranceAndExit();
}

void Field::CreateTiles(int w, int  h) {
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
            Tiles[i][j]->content = NULL;
        }
    }
}

void Field::CreateTiles() {
    CreateTiles(width, height);
}

void Field::DeleteTiles() {
    for (int i = 0; i < width; i++)
    {
        delete [] Tiles[i];
    }
    delete [] Tiles;
}

Field::Field(Field& other){
    width = other.width;
    height = other.height;

    Tiles = new Tile** [other.width];
    for (int i = 0; i < other.width; i++)
    {
        Tiles[i] = new Tile*[other.width];
    }

    for(int i = 0; i < other.width; i++)
    {
        for(int j = 0; j < other.height; j++)
        {
            Tiles[i][j] = new Tile(other.Tiles[i][j]->GetType());
            *Tiles[i][j]->content = *other.Tiles[i][j]->content;
        }
    }
}

Field::Field(Field&& other){
    swap(width, other.width);
    swap(height, other.height);
    swap(Tiles, other.Tiles);
}

Field& Field::operator=(Field&& other){
    if (this != &other)
    {
        swap(width, other.width);
        swap(height, other.height);
        swap(Tiles, other.Tiles);
    }
}

Field& Field::operator=(Field& other){
    if (this != &other)
    {
        DeleteTiles();

        width = other.width;
        height = other.height;

        Tiles = new Tile** [other.width];
        for (int i = 0; i < other.width; i++)
        {
            Tiles[i] = new Tile*[other.width];
        }

        for(int i = 0; i < other.width; i++)
        {
            for(int j = 0; j < other.height; j++)
            {
                Tiles[i][j] = new Tile(other.Tiles[i][j]->GetType());
                *Tiles[i][j]->content = *other.Tiles[i][j]->content;
            }
        }
    }
    return *this;
};




void Field::CreatePuddle(int min_size, int max_size){
    int x_for_puddle = rand() % width;
    int y_for_puddle = rand() % height;
    int puddle_radius = min_size + rand() % (max_size - min_size);
    for (int i = -puddle_radius; i <=puddle_radius; i++)
    {
        for (int j = -puddle_radius; j <=puddle_radius; j++)
        {
            if (i*i + j*j <= puddle_radius*puddle_radius)
            {
                if(x_for_puddle+i < width && x_for_puddle+i >= 0 && y_for_puddle+j < width && y_for_puddle+j >= 0)
                    Tiles[x_for_puddle+i][y_for_puddle+j]->SetType(WATER);
            }
        }
    }
}

void Field::CreateEntranceAndExit(){
    //create entrance tile
    int x_for_entrance = rand() % width ;
    int y_for_entrance = rand() % height;
    while(Tiles[x_for_entrance][y_for_entrance]->GetType() == WATER )
    {
        x_for_entrance = rand() % width;
        y_for_entrance = rand() % height;
    }
    Tiles[x_for_entrance][y_for_entrance]->content = new Entrance();

    int x_for_exit = rand() % width;
    int y_for_exit = rand() % height;
    while(Tiles[x_for_exit][y_for_exit]->GetType() == WATER || CheckAround<Entrance>(x_for_exit, y_for_exit))
    {
        x_for_exit = rand() % width;
        y_for_exit = rand() % height;
    }
    Tiles[x_for_exit][y_for_exit]->content = new Exit();
};

Field::~Field(){
    DeleteTiles();
}

