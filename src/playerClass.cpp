//
// Created by waylon on 5/21/26.
//

#include "playerClass.h"
#include "EntityClass.h"
#include "InputHandler.h"

Player::Player() = default;
Player::Player(const Position pos,const BoxSize hbs): Entity{pos,hbs,true, true} {this->setColor(RGBAlpha{255,255,255,255});}
;


//void Player::updateChildren(AppContext& app, float deltaTime){}

void Player::childMove(const AppContext &app,const float deltaTime) {
    //checks to see if movment is being inputted before trying to move
    if (auto [x, y] = InputHandler::getInputDirection(); x == 0.0f && y == 0.0f) {return;}
    else {
        const float movementReqX = (x * speed)*deltaTime;
        const float movementReqY = (y * speed)*deltaTime;
        attemptMovement(app,movementReqX,movementReqY);
    }
}



