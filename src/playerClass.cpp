//
// Created by waylon on 5/21/26.
//

#include "playerClass.h"
#include "EntityClass.h"
#include "SDL3/SDL.h"
Player::Player() = default;
Player::Player(Position pos,BoxSize hbs): Entity{pos,hbs} {this->setColor(RGBAlpha{255,255,255,255});}
Player::Player(Position pos, bool canCollide) : Entity{pos,canCollide} {};



void Player::update(AppContext& app, float deltaTime){
    VelocityVector velocity = InputHandler::getInputDirection();
    Position newPosition;
    newPosition.x = this->getPosition().x + (velocity.x * speed)*deltaTime;
    newPosition.y = this->getPosition().y + (velocity.y * speed)*deltaTime;
    this->setPosition(newPosition);
    std::cout << newPosition.x << "," << newPosition.y << std::endl;
}

