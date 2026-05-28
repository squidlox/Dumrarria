//
// Created by waylon on 5/21/26.
//
#include "EntityClass.h"
#include "cmath"
#include <iostream>

Entity::Entity() = default;

Entity::Entity(const Position pos, const BoxSize hbs, const bool canCollide, const bool moveable)
        : position{pos}, hitBoxSize{hbs}, boxSides{pos.y,pos.y-hbs.height, pos.y, pos.y+hbs.width},
          canCollidePriv{canCollide}, isMoveablePriv{moveable}{}

//getters
Position Entity::getPosition()const{
    return this->position;
}
BoxSize Entity::getHitBoxSize()const {
    return this->hitBoxSize;
}
BoxSides Entity::getBoxSides() {
    this->boxSides.top = this->position.y;
    this->boxSides.bottom = this->position.y + this->hitBoxSize.height;
    this->boxSides.left = this->position.x;
    this->boxSides.right = this->position.x + this->hitBoxSize.width;
    return this->boxSides;
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
void Entity::update(const AppContext& app, float deltaTime) {
    if (this->isMoveablePriv == true) {
        this->childMove(app, deltaTime);
    }
    this->updateChildren(app, deltaTime);
}
void Entity::updateChildren(const AppContext& app, float deltaTime) {

}
void Entity::childMove(const AppContext& app, float deltaTime){
}
void Entity::setColor(const RGBAlpha inRGBA) {
    this->rgba = inRGBA;
}

//todo possible opimization for entity movement: bounding box collision
void Entity::attemptMovement(const AppContext &app, float dirX, float dirY) {
    if (isMoveablePriv == true) {
        this->attemptMovementX(app,dirX);
        this->attemptMovementY(app, dirY);
    }
    else {
        std::cout << "attemped to move an UnMovable entity" << isMoveablePriv<< std::endl;
    }
}

void Entity::attemptMovementX(const AppContext &app,float dirX) {
    remainingMovementX += dirX;
    if (int wholePixelsToMove = static_cast<int>(std::round(remainingMovementX)); wholePixelsToMove != 0) {
        remainingMovementX -= static_cast<float>(wholePixelsToMove);
        const int movementDirection = (wholePixelsToMove > 0) ? 1 : -1;

        while (wholePixelsToMove != 0) {
            float nextPosition = this->getPosition().x + static_cast<float>(movementDirection);
            if (!this->checkCollision(app,Position{nextPosition, this->getPosition().y})){
                this->setPosition(Position{nextPosition,this->getPosition().y});
                wholePixelsToMove -= movementDirection;
            }
            else {
                break;
            }
        }
    }
}
void Entity::attemptMovementY(const AppContext &app, const float dirY) {
    remainingMovementY += dirY;
    if (int wholePixelsToMove = static_cast<int>(std::round(remainingMovementY)); wholePixelsToMove != 0) {
        remainingMovementY -= static_cast<float>(wholePixelsToMove);
        const int movementDirection = (wholePixelsToMove > 0) ? 1 : -1;

        while (wholePixelsToMove != 0) {
            float nextPosition = this->getPosition().y + static_cast<float>(movementDirection);

            if (!this->checkCollision(app,Position{this->getPosition().x,nextPosition}))
            {
                this->setPosition(Position{this->getPosition().x,nextPosition});
                wholePixelsToMove -= movementDirection;
            }
            else {
                break;
            }
        }
    }
}
bool Entity::checkCollision(const AppContext &app,const Position nextPosition) const {
    BoxSides nextBoxSides = boxSides;
    nextBoxSides.top = nextPosition.y; nextBoxSides.bottom = nextPosition.y + this->hitBoxSize.height;
    nextBoxSides.left = nextPosition.x; nextBoxSides.right = nextPosition.x + this->hitBoxSize.width;

    for (const auto& entityPtr : app.entities) {

        if (entityPtr.get() == this || entityPtr->canCollide() == false) {
            continue;
        }
        BoxSides indexEntitySides = entityPtr->getBoxSides();
        if (nextBoxSides.top < indexEntitySides.bottom && nextBoxSides.bottom > indexEntitySides.top &&
            nextBoxSides.left < indexEntitySides.right && nextBoxSides.right > indexEntitySides.left) {
            return true;
            }
    }
    return false;
}

Entity::~Entity() = default;

