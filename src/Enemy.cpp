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
    if (app.player) {
        Position playerPos = app.player->getPosition();
        Position enemyPos = this->getPosition();
        if (playerPos.x == enemyPos.x && playerPos.y == enemyPos.y){ return;};
        VelocityVector playerDirection = VelocityVector{playerPos.x-enemyPos.x, playerPos.y - enemyPos.y};
        float cSquared = sqrt((playerDirection.x * playerDirection.x) + (playerDirection.y * playerDirection.y));
        playerDirection.x = (playerDirection.x/cSquared)* speed*deltaTime;
        playerDirection.y = (playerDirection.y/cSquared)* speed*deltaTime;
        attemptMovement(playerDirection.x, playerDirection.y);
    }
}
//setters
