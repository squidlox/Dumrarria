//
// Created by waylon on 5/24/26.
//
#include "Enemy.h"
#include "playerClass.h"
#include <cmath>


Enemy::Enemy(const Position pos, const BoxSize hbs): Entity{pos,hbs,true,true}{};

//getters

void Enemy::updateChildren(const AppContext& app, float deltaTime){}
void Enemy::childMove(const AppContext &app, const float deltaTime) {
    if (app.player) {
        Position playerPos = app.player->getPosition();
        Position enemyPos = this->getPosition();
        if (playerPos.x == enemyPos.x && playerPos.y == enemyPos.y){ return;};
        auto playerDirection = VelocityVector{playerPos.x-enemyPos.x, playerPos.y - enemyPos.y};
        const auto cSquared = static_cast<float>(sqrt(static_cast<double>((playerDirection.x * playerDirection.x) + (playerDirection.y * playerDirection.y))));
        playerDirection.x = (playerDirection.x/cSquared)* speed*deltaTime;
        playerDirection.y = (playerDirection.y/cSquared)* speed*deltaTime;
        attemptMovement(app,playerDirection.x, playerDirection.y);
    }
}
//setters
