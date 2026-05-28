//
// Created by waylon on 5/24/26.
//
#ifndef DUMRARRIA_APPCONTEXT_H
#define DUMRARRIA_APPCONTEXT_H
#include <memory>
#include <SDL3/SDL.h>
#include "vector"

class Entity;
class Player;

struct AppContext {
    float deltaTime{0.0f};
    std::vector<std::unique_ptr<Entity>> entities;
    SDL_Renderer *renderer;
    Player *player{nullptr};
    ScreenSize screenSize{1920,1080};
};
#endif //DUMRARRIA_APPCONTEXT_H
