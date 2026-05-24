//
// Created by waylon on 5/24/26.
//
#include "InputHandler.h"

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
    return velocityVector;
}