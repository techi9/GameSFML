//
// Created by tucha on 10/21/2021.
//

#ifndef GAMESFML_CONTROLLERKEYBOARD_H
#define GAMESFML_CONTROLLERKEYBOARD_H
#include "Player.h"
#include "../../Game/Controller.h"

class ControllerKeyboard : public Controller{
private:
    bool attacked = false;
    Entity *player;
    int speedX = 0;
    int speedY = 0;
public:
    ControllerKeyboard(Entity *player);
    void control();
};


#endif //GAMESFML_CONTROLLERKEYBOARD_H
