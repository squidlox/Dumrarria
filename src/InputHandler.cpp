//
// Created by waylon on 5/24/26.
//
#include "InputHandler.h"
#include <cmath>
#include "game.h"

#include "playerClass.h"

VelocityVector InputHandler::getInputDirection()
{
    const bool* state = SDL_GetKeyboardState(nullptr);
    VelocityVector velocityVector{0,0};
    SDL_Scancode upCode = keyMap.at(UP);
    SDL_Scancode downCode = keyMap.at(DOWN);
    SDL_Scancode leftCode = keyMap.at(LEFT);
    SDL_Scancode rightCode = keyMap.at(RIGHT);
    if (state[upCode]){velocityVector.y -= 1;}
    if (state[downCode]){velocityVector.y += 1;}
    if (state[leftCode]){velocityVector.x -= 1;}
    if (state[rightCode]){velocityVector.x += 1;}
    if (velocityVector.y != 0 && velocityVector.x != 0) {
        float cSquared = sqrt((velocityVector.x * velocityVector.x) + (velocityVector.y * velocityVector.y));
        velocityVector.x = velocityVector.x/cSquared;
        velocityVector.y = velocityVector.y/cSquared;
    }
    return velocityVector;
}
void InputHandler::devChangeHealth(AppContext &app) {
    Game game;
    const bool* state = SDL_GetKeyboardState(nullptr);
    Player *player = app.player;
    SDL_Scancode addHealth = keyMap.at(ADDHEALTH);
    SDL_Scancode removeHealth = keyMap.at(REMOVEHEALTH);
    if (state[addHealth]) {
        player->setHealth(player->getHealth() + 0.001);
    }
    if (state[removeHealth]) {
        player->setHealth(player->getHealth() - 0.001);
    }
}