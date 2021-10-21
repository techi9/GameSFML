#include "Player.h"

Player::Player(int xOfEnt, int yofEnt){
    health = 100;
    damage = 2;
    maxSpeed = 1;
    setPosition(xOfEnt, yofEnt);
}

//TODO: finish