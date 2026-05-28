//
// Created by waylon on 5/21/26.
//
#include "EntityClass.h"

Entity::Entity() = default;

Entity::Entity(Position pos, BoxSize hbs, bool canCollide, bool moveable)
        : position{pos}, hitBoxSize{hbs}, canCollidePriv{canCollide}, isMoveablePriv{moveable},
            boxSides{pos.y,pos.y-hbs.height, pos.y, pos.y+hbs.width}{}

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
void Entity::update(AppContext& app, float deltaTime) {
    if (this->isMoveablePriv == true) {
        this->childMove(app, deltaTime);
    }
    this->updateChildren(app, deltaTime);
}
void Entity::updateChildren(AppContext& app, float deltaTime) {

}
void Entity::childMove(AppContext& app, float deltaTime){
}
void Entity::setColor(const RGBAlpha inRGBA) {
    this->rgba = inRGBA;
}

//todo possible opimization for entity movement: bounding box collision
void Entity::attemptMovement(AppContext &app, float dirX, float dirY) {
    if (isMoveablePriv == true) {
        this->attemptMovementX(app,dirX);
        this->attemptMovementY(app, dirY);
    }
    else {
        std::cout << "attemped to move an UnMovable entity" << isMoveablePriv<< std::endl;
    }
}

void Entity::attemptMovementX(AppContext &app,float dirX) {
    remainingMovementX += dirX;
    int wholePixelsToMove = std::round(remainingMovementX);
    if (wholePixelsToMove != 0) {
        remainingMovementX -= wholePixelsToMove;
        int movementDirection = (wholePixelsToMove > 0) ? 1 : -1;

        while (wholePixelsToMove != 0) {
            float nextPosition = this->getPosition().x + movementDirection;
            if (!this->checkCollision(app,Position{nextPosition, this->getPosition().y}))/*<-- impliment AABB colission fun here*/ {
                this->setPosition(Position{nextPosition,this->getPosition().y});
                wholePixelsToMove -= movementDirection;
            }
            else {
                break;
            }
        }
    }
}
void Entity::attemptMovementY(AppContext &app,float dirY) {
    remainingMovementY += dirY;
    int wholePixelsToMove = std::round(remainingMovementY);
    if (wholePixelsToMove != 0) {
        remainingMovementY -= wholePixelsToMove;
        int movementDirection = (wholePixelsToMove > 0) ? 1 : -1;

        while (wholePixelsToMove != 0) {
            float nextPosition = this->getPosition().y + movementDirection;

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
bool Entity::checkCollision(const AppContext &app,const Position nextPosition) {
    BoxSides nextBoxSides = boxSides;
    nextBoxSides.top = nextPosition.y; nextBoxSides.bottom = nextPosition.y + this->hitBoxSize.height;
    nextBoxSides.left = nextPosition.x; nextBoxSides.right = nextPosition.x + this->hitBoxSize.width;

    for (int i = 0; i < app.entities.size(); i++) {
        if (app.entities.at(i).get() == this) {continue;}
       BoxSides UnKnEntitySides = app.entities.at(i)->getBoxSides();
        if (nextBoxSides.top < UnKnEntitySides.bottom && nextBoxSides.bottom > UnKnEntitySides.top &&
            nextBoxSides.left < UnKnEntitySides.right && nextBoxSides.right > UnKnEntitySides.left) {
            return true;
        }
    }
    return false;
}

Entity::~Entity() {

}

