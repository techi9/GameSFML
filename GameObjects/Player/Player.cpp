#include "Player.h"
#include "iostream"
Player::Player(int xOfEnt, int yofEnt){
    health = 100;
    damage = 10;
    maxSpeed = 0.3;
    attackRadius = 100;
    attackSpeed = 2;
    setPosition(xOfEnt, yofEnt);
}



