//
// Created by waylon on 5/24/26.
//
#ifndef DUMRARRIA_ENEMY_H
#define DUMRARRIA_ENEMY_H

#include "EntityClass.h"

class Enemy : public Entity {
private:
    float speed{75};
    void updateChildren(const AppContext& app, float deltaTime) override;
    void childMove(const AppContext &app, float deltaTime)override;

public:
    Enemy(Position pos,BoxSize hbs);

    //getters

    //setters
    void setSpeed(float const s_Speed){this->speed = s_Speed;};

};
#endif //DUMRARRIA_ENEMY_H
