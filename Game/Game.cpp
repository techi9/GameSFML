#include "Game.h"
#include <chrono>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define TILE_SIZE 32

bool isDeleted(Entity* ent){
    if(ent->isDead()){
        delete ent;
        return true;
    }
    else return false;
}

Game::Game(int w, int h){
    // create the window
    this->w = w;
    this->h = h;
    auto wind = new sf::RenderWindow(sf::VideoMode( w * TILE_SIZE,h * TILE_SIZE), "My window", sf::Style::Titlebar | sf::Style::Close);
    this->window = wind;




    srand (time(nullptr)-23);
    field = new Field(w, h);
    field->Init();
    fview = new FieldView(field, "../Field/TileSet");
    fview->DrawField();
    objectView = new ObjectView(&EntitiesList, "../Textures");
    colMap = new CollsionMap(*field, TILE_SIZE);

    Player* player = new Player(50, 50); //create palyer
    addController(new ControllerKeyboard(player));
    CreateEntity(player);

    Turret* turret = new Turret(200, 100); //create first enemy
    addController(new EnemyController(*colMap ,*turret));
    CreateEntity(turret);

    Troll* troll = new Troll(500, 500);
    addController(new EnemyController(*colMap, *troll));
    CreateEntity(troll);

    Goblin* goblin = new Goblin(100, 100);
    addController(new EnemyController(*colMap, *goblin));
    CreateEntity(goblin);


    CreateItem(new Hyperstone(150, 150));


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

        performAttacks();
        objectView->Update();


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

void Game::UpdateEntities() {


    for (auto *cnt : Controllers){
        cnt->control();
    }


    bool stopR = false;
    bool stopL = false;
    bool stopUp = false;
    bool stopD = false;
    //collider
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

void Game::performAttacks() {
    vector<Entity*> entToAttack;
    for(auto &ent : EntitiesList){
        if (ent->checkAttack()){
            entToAttack = findNearEntities(*ent, ent->getAttackRadius());
            for(auto &eToAttack : entToAttack){
                cout<<"attacked\n";
                ent->attack(*eToAttack);
            }
        }
    }
    EntitiesList.erase(std::remove_if(EntitiesList.begin(), EntitiesList.end(), isDeleted), EntitiesList.end());
}


vector<Entity*> Game::findNearEntities(Entity &ent, float radius) {
    float xt = 0, yt = 0;
    vector<Entity*> foundEntities;
    for(auto &entity : EntitiesList){
        //x,y  x1,y1  x1-x, y1-y sqr(x1,y1)<=radius
        xt = entity->getPosition().first - ent.getPosition().first ;
        yt = entity->getPosition().second - ent.getPosition().second;
        if((xt*xt + yt*yt <= radius*radius) && (ent.getPosition().first != entity->getPosition().first && ent.getPosition().second != entity->getPosition().second)){
            foundEntities.push_back(entity);
        }
    }
    return foundEntities;
}

void Game::addController(Controller *cont) {
    Controllers.push_back(cont);
}

void Game::CreateItem(Item *item) {
    ItemList.push_back(item);
}



