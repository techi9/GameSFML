#include "Game.h"
#include <chrono>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <time.h>
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

    colMap = new CollsionMap(*field, TILE_SIZE);
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



        // clear the window with black color
        window->clear(sf::Color::Black);

        // draw everything here...
        window->draw(*fview);
        // end the current frame
        window->display();
    }
}

Game::~Game(){
    delete fview;
    delete field;
}
