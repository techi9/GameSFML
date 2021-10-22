//
// Created by tucha on 10/21/2021.
//

#ifndef GAMESFML_CONTROLLERKEYBOARD_H
#define GAMESFML_CONTROLLERKEYBOARD_H
#include "Player.h"

class ControllerKeyboard {
private:
    Player *player;
    int speedX = 0;
    int speedY = 0;
public:
    ControllerKeyboard(Player *player);
    void Control();
};


#endif //GAMESFML_CONTROLLERKEYBOARD_H