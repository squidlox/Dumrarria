//
// Created by waylon on 5/21/26.
//
#include "EntityClass.h"

Entity::Entity() = default;
Entity::Entity(const float x, const float y): position{x, y}{}
Entity::Entity(const float x,const float y, const bool canCollide) : position{x, y}, canCollidePriv{canCollide}{}

//getters
Position Entity::getPosition()const{
    return this->position;
}
BoxSize Entity::getHitBoxSize()const {
    return this->hitBoxSize;
}
bool Entity::canCollide()const{
    return this->canCollidePriv;
}


//setters

void Entity::setPosition(const float x, const float y) {
    this->position.x = x;
    this->position.y = y;
}
void Entity::setPosition(const Position& pos) {
    this->position = pos;
}
void Entity::setHitBoxSize(const BoxSize size) {
    this->hitBoxSize = size;
}
void Entity::setCanCollide(const bool canCollide) {
    this->canCollidePriv = canCollide;
}

