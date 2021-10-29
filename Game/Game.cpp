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
    bool stopR = false; // TODO: Add collider
    bool stopL = false; // TODO: Add collider
    bool stopUp = false;
    bool stopD = false;
    for(auto &ent : EntitiesList){
        stopR = false;
        stopL = false;
        stopUp = false;
        stopD = false;
        if(!(colMap->at(int(ceil(ent->getPosition().first + TILE_SIZE)),
                        int(ceil(ent->getPosition().second + 1)))) ||
                        !(colMap->at(ent->getPosition().first + 1 + TILE_SIZE, ent->getPosition().second + TILE_SIZE - 1)))
        {
            stopR = true;
        }

        if(!(colMap->at(int(ceil(ent->getPosition().first) - 1),
                     int(ceil(ent->getPosition().second + 1)))) ||
                     !(colMap->at(int(ceil(ent->getPosition().first) - 1), ent->getPosition().second + TILE_SIZE - 1)))
        {
            stopL = true;
        }

        if(!(colMap->at(int(ceil(ent->getPosition().first)),
                        int(ceil(ent->getPosition().second)))) ||
                !(colMap->at(int(ceil(ent->getPosition().first + TILE_SIZE - 2)),
                           int(ceil(ent->getPosition().second)))))
        {
            stopUp = true;
        }

        if(!(colMap->at(int(ceil(ent->getPosition().first) + 1),
                        int(ceil(ent->getPosition().second)) + TILE_SIZE-1)) ||
                        !(colMap->at(ent->getPosition().first - 1 + TILE_SIZE, ent->getPosition().second + TILE_SIZE)))
        {
            stopD = true;
        }

        if(stopR){
            ent->setSpeed(ent->getSpeed().first > 0 ? 0 : ent->getSpeed().first, ent->getSpeed().second);
        }
        if(stopL){
            ent->setSpeed(ent->getSpeed().first < 0 ? 0 : ent->getSpeed().first, ent->getSpeed().second);
        }
        if(stopUp){
            ent->setSpeed(ent->getSpeed().first, ent->getSpeed().second < 0 ? 0 : ent->getSpeed().second);
        }
        if(stopD){
            ent->setSpeed(ent->getSpeed().first, ent->getSpeed().second > 0 ? 0 : ent->getSpeed().second);
        }
        ent->move();
    }
}

