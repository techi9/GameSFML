#include "Game.h"
#include <chrono>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "../GameObjects/Player/Player.h"
#define TILE_SIZE 32

Game::Game(int w, int h){
    // create the window
    this->w = w;
    this->h = h;
    auto wind = new sf::RenderWindow(sf::VideoMode( w * TILE_SIZE,h * TILE_SIZE), "My window", sf::Style::Titlebar | sf::Style::Close);
    this->window = wind;

    srand (time(NULL));
    field = new Field(w, h);
    field->Init();
    fview = new FieldView(field, "../Field/TileSet");
    fview->DrawField();
    objectView = new ObjectView(&EntitiesList, "../Textures");

    colMap = new CollsionMap(*field, TILE_SIZE);

    Player* player = new Player(50, 50);
    playerController = new ControllerKeyboard(player);
    CreateEntity(player);


    RunLoop();
}

void Game::RunLoop()
{
    while (window->isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }

        UpdateEntities();
        objectView->Update();
        playerController->Control();


        // list of entities / update every obj pos using speed
        // than controllers (controller(player)) calls other methods like interact or attack


        // clear the window with black color
        window->clear(sf::Color::Black);

        // draw everything here...
        window->draw(*fview);
        window->draw(*objectView);
        // end the current frame
        window->display();
    }
}

void Game::CreateEntity(Entity *ent){
    EntitiesList.push_back(ent);
}

Game::~Game(){
    delete fview;
    delete field;
}

void Game::UpdateEntities() { //checks in both directions but not diagonally
    bool stop = false;
    for(auto &ent : EntitiesList){
        stop = false;
        for(int x_add = 0; x_add < ceil(ent->getSpeed().first); x_add++){
            if (!(colMap->at(ent->getPosition().first + x_add, ent->getPosition().second)))  //TODO: fix to check in other direction
            {
                stop = true;
                break;
            }
        }

        for(int y_add = 0; y_add < ceil(ent->getSpeed().second); y_add++){
            if (!(colMap->at(ent->getPosition().first , ent->getPosition().second) + y_add))
            {
                stop = true;
                break;
            }
        }

        if(!stop){
            ent->move();
        }
        else{
            continue;
        }
    }
}

