//
// Created by waylon on 5/24/26.
//
#ifndef DUMRARRIA_ENEMY_H
#define DUMRARRIA_ENEMY_H

#include "EntityClass.h"

class Enemy : public Entity {
private:
    float speed{75};
public:
    Enemy();
    Enemy(Position pos,BoxSize hbs);

    //getters

    void update(AppContext& app, float deltaTime) override;
    //setters
    void setSpeed(float speed){this->speed = speed;};


    ~Enemy() override = default;
};
#endif //DUMRARRIA_ENEMY_H
