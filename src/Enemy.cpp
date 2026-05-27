//
// Created by waylon on 5/24/26.
//
#include "Enemy.h"
#include "playerClass.h"
#include <cmath>

Enemy::Enemy(){}
Enemy::Enemy(Position pos, BoxSize hbs): Entity{pos,hbs,true,true}{/*this->setColor(RGBAlpha{0,240,0,0});*/};

//getters

void Enemy::update(AppContext& app, float deltaTime){

    float newPositionY = this->getPosition().y + speed*deltaTime;

    this->setPosition(Position{this->getPosition().x, newPositionY});


    /*if (app.player) {
        Position playerPos = app.player->getPosition();
        Position enemyPos = this->getPosition();
        VelocityVector playerDirection = VelocityVector{playerPos.x-enemyPos.x, playerPos.y - enemyPos.y};
        Position newPosition;
        float cSquared = sqrt((playerDirection.x * playerDirection.x) + (playerDirection.y * playerDirection.y));
        playerDirection.x = playerDirection.x/cSquared;
        playerDirection.y = playerDirection.y/cSquared;
        newPosition.x = this->getPosition().x + (playerDirection.x * speed)*deltaTime;
        newPosition.y = this->getPosition().y + (playerDirection.y * speed)*deltaTime;
        this->setPosition(newPosition);
    }*/
}
//setters
