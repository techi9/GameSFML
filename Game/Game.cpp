#include "Game.h"
#include <chrono>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <time.h>

Game::Game(int w, int h){
    // create the window
    sf::RenderWindow window(sf::VideoMode(1280,720), "My window", sf::Style::Titlebar | sf::Style::Close);
    this->window = &window;

    srand (time(NULL));
    field = new Field(w, h);
    field->Init();
    fview = new FieldView(field, "../Field/TileSet");
    fview->DrawField();

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
            // "close requested" event: we close the window
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
