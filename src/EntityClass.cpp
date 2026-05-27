//
// Created by waylon on 5/21/26.
//
#include "EntityClass.h"

Entity::Entity() = default;

Entity::Entity(Position pos, BoxSize hbs, bool canCollide, bool moveable)
        : position{pos}, hitBoxSize{hbs}, canCollidePriv{canCollide}, isMoveablePriv{moveable} {}

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
bool Entity::isMoveable()const {
    return this->isMoveablePriv;
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
void Entity::setIsMoveable(const bool moveable) {
    this->isMoveablePriv = moveable;
}
void Entity::update(AppContext& app, float deltaTime) {
}
void Entity::setColor(const RGBAlpha inRGBA) {
    this->rgba = inRGBA;
}

//todo possible opimization for entity movement: bounding box collision
void Entity::attemptMovement(float dirX, float dirY) {
    if (isMoveablePriv == true) {
        this->attemptMovementX(dirX);
        this->attemptMovementY(dirY);
    }
    else {
        std::cout << "attemped to move an UnMovable entity" << isMoveablePriv<< std::endl;
    }
}

void Entity::attemptMovementX(float dirX) {
    remainingMovementX += dirX;
    int wholePixelsToMove = std::round(remainingMovementX);
    if (wholePixelsToMove != 0) {
        remainingMovementX -= wholePixelsToMove;
        int movementDirection = (wholePixelsToMove > 0) ? 1 : -1;

        while (wholePixelsToMove != 0) {
            float nextPosition = this->getPosition().x + movementDirection;
            if (true == true)/*<-- impliment AABB colission fun here*/ {
                this->setPosition(Position{nextPosition,this->getPosition().y});
                wholePixelsToMove -= movementDirection;
            }
            else {
                std::cout << "collision detected" << std::endl;
            }
        }
    }
}
void Entity::attemptMovementY(float dirY) {
    remainingMovementY += dirY;
    int wholePixelsToMove = std::round(remainingMovementY);
    if (wholePixelsToMove != 0) {
        remainingMovementY -= wholePixelsToMove;
        int movementDirection = (wholePixelsToMove > 0) ? 1 : -1;

        while (wholePixelsToMove != 0) {
            float nextPosition = this->getPosition().y + movementDirection;
            if (true ==true)/*<-- impliment AABB colission fun here*/ {
                this->setPosition(Position{this->getPosition().x,nextPosition});
                wholePixelsToMove -= movementDirection;
            }
            else {
                std::cout << "collision detected" << std::endl;
            }
        }
    }
}

Entity::~Entity() {

}

