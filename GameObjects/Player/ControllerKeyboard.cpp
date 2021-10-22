//
// Created by tucha on 10/21/2021.
//

#include "ControllerKeyboard.h"
#include "SFML/Graphics.hpp"

ControllerKeyboard::ControllerKeyboard(Player *player) {
    this->player = player;
}

void ControllerKeyboard::Control() { //TODO: fix moving diagonally
    bool speedChanged = false;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        speedX =- 1;
        speedChanged = true;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        speedX = 1;
        speedChanged = true;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        speedY = -1;
        speedChanged = true;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        speedY = 1;
        speedChanged = true;
    }
    if(!speedChanged)
    {
        speedX = 0;
        speedY = 0;
    }
    speedChanged = false;
    player->setSpeed(speedX, speedY);
}
