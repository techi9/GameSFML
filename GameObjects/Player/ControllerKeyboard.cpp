//
// Created by tucha on 10/21/2021.
//

#include "ControllerKeyboard.h"
#include "SFML/Graphics.hpp"

ControllerKeyboard::ControllerKeyboard(Entity *player) {
    this->player = player;
}

void ControllerKeyboard::control() {

    attacked = false;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !attacked){
        player->attack();
        attacked = true;
    }
    else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        attacked = false;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        speedX = - 1;
    }
    else
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        speedX = 1;
    }
    else {speedX = 0;}
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        speedY = -1;
    }else
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        speedY = 1;
    }else {speedY = 0;}

    player->setSpeed(speedX, speedY);
}
