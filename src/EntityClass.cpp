//
// Created by waylon on 5/21/26.
//
#include "EntityClass.h"

Entity::Entity() = default;
Entity::Entity(Position pos,BoxSize hbs): position(pos), hitBoxSize(hbs) {}
Entity::Entity(const Position pos, const bool canCollide) : position{pos}, canCollidePriv{canCollide}{}

//getters
Position Entity::getPosition()const{
    return this->position;
}
BoxSize Entity::getHitBoxSize()const {
    return this->hitBoxSize;
}
RGBAlpha Entity::getColor() const {
    return this->rgba;
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
void Entity::update(AppContext& app, float deltaTime) {

}
void Entity::setColor(const RGBAlpha inRGBA) {
    this->rgba = inRGBA;
}
Entity::~Entity() {

}

