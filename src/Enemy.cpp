//
// Created by waylon on 5/24/26.
//
#include "Enemy.h"
#include "playerClass.h"
#include <cmath>

Enemy::Enemy(){}
Enemy::Enemy(Position pos,BoxSize hbs): Entity(pos,hbs){this->setColor(RGBAlpha{0,240,0,0});};
Enemy::Enemy(Position pos, bool canCollide):Entity(pos,canCollide){};

//getters
RGBAlpha Enemy::getHitBoxColor()const {
    return hitBoxColor;
}
void Enemy::update(AppContext& app, float deltaTime){
    if (app.player) {
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
    }
}
//setters
void Enemy::setHitBoxColor(RGBAlpha hitBoxColor) {
    this->hitBoxColor = hitBoxColor;
}