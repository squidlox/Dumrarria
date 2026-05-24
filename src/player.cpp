//
// Created by waylon on 5/21/26.
//

#include "player.h"
#include "SDL3/SDL.h"
Player::Player() = default;
Player::Player(Position pos,BoxSize hbs): Entity{pos,hbs} {};
Player::Player(float x, float y, bool canCollide) : Entity{x,y,canCollide} {};


RGBAlpha Player::getHitBoxColor() const {
    return this->hitBoxColor;
}

void Player::setHitBoxColor(const RGBAlpha pHitBoxColor) {
    this->hitBoxColor = pHitBoxColor;
}
