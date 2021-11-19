//
// Created by tucha on 11/18/2021.
//

#ifndef GAMESFML_ENEMYCONTROLLER_H
#define GAMESFML_ENEMYCONTROLLER_H
#include "../../Game/CollsionMap.h"
#include "../Entity.h"
#include "../../Game/Controller.h"

class EnemyController : public Controller{

    CollsionMap &field;
    Entity &ent;

public:
    EnemyController(CollsionMap &field, Entity &ent);
    void control() override;
};


#endif //GAMESFML_ENEMYCONTROLLER_H
