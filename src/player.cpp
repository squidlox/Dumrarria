//
// Created by waylon on 5/21/26.
//

#include "player.h"
#include "EntityClass.h"
#include "SDL3/SDL.h"
Player::Player() = default;
Player::Player(Position pos,BoxSize hbs): Entity{pos,hbs} {};
Player::Player(Position pos, bool canCollide) : Entity{pos,canCollide} {};


RGBAlpha Player::getHitBoxColor() const {
    return this->hitBoxColor;
}
void Player::update(float deltaTime) {
    VelocityVector velocity = InputHandler::getInputDirection();
    Position newPosition;
    newPosition.x = this->getPosition().x + (velocity.x * speed);
    newPosition.y = this->getPosition().y + (velocity.y * speed);
    this->setPosition(newPosition);
    std::cout << newPosition.x << "," << newPosition.y << std::endl;
}
void Player::setHitBoxColor(const RGBAlpha pHitBoxColor) {
    this->hitBoxColor = pHitBoxColor;
}
