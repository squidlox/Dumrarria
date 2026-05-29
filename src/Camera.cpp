//
// Created by waylon on 5/28/26.
//

#include "Camera.h"

#include "playerClass.h"


void Camera::update(const AppContext &app) {
    //ensure camera will size will be synced with renderer for now
    //TODO possibly make this adjustable for player in future
    this->boxSize.width = static_cast<float>(app.screenSize.width);
    this->boxSize.height = static_cast<float>(app.screenSize.height);

    //find player pos and ceneter
    Position playerPosition = app.player->getPosition();
    BoxSize playerBoxSize = app.player->getHitBoxSize();

    Position playerPosCentered = Position(playerPosition.x + playerBoxSize.width / 2.0f, playerPosition.y + playerBoxSize.height / 2.0f);
    float drawOffsetX = playerPosCentered.x - this->boxSize.width / 2.0f;
    float drawOffsetY = playerPosCentered.y - this->boxSize.height / 2.0f;
    this->drawOffest = {drawOffsetX, drawOffsetY};
}
Position Camera::getDrawOffest() const{
    return this->drawOffest;
}