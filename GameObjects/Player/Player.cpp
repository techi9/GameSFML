#include "Player.h"

Player::Player(int xOfEnt, int yofEnt){
    health = 100;
    damage = 2;
    maxSpeed = 0.3;
    setPosition(xOfEnt, yofEnt);
}

//TODO: finish