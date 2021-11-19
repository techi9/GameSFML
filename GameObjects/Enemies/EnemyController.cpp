//
// Created by tucha on 11/18/2021.
//

#include "EnemyController.h"
#include "iostream"
EnemyController::EnemyController(CollsionMap &field, Entity &ent) : field(field), ent(ent) { //field is just a collision map here

}

void EnemyController::control() {
    static bool goUp = false;
    if (field.at(ent.getPosition().first, ent.getPosition().second +32 + 2) && !goUp)
    {

        ent.setSpeed(0, 100);
    }
    else if (field.at(ent.getPosition().first, ent.getPosition().second- 2))
    {
        ent.setSpeed(0, -100);
        goUp = true;
    }
    else {goUp = false;}

    ent.attack();
}
