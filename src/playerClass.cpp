//
// Created by waylon on 5/21/26.
//

#include "playerClass.h"
#include "EntityClass.h"
#include "SDL3/SDL.h"
Player::Player() = default;
Player::Player(Position pos,BoxSize hbs): Entity{pos,hbs,true, true} {this->setColor(RGBAlpha{255,255,255,255});}
;


void Player::update(AppContext& app, float deltaTime){
    VelocityVector velocity = InputHandler::getInputDirection();
    if (velocity.x == 0 && velocity.y == 0) {}
    else {
        float movementReqX = (velocity.x * speed)*deltaTime;
        float movementReqY = (velocity.y * speed)*deltaTime;
        attemptMovement(movementReqX,movementReqY);
    }
}



