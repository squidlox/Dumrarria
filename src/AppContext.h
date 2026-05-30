//
// Created by waylon on 5/24/26.
//
#ifndef DUMRARRIA_APPCONTEXT_H
#define DUMRARRIA_APPCONTEXT_H
#include <memory>
#include <SDL3/SDL.h>
#include "vector"
#include "globalDataStructs.h"
#include "TextureManager.h"

class Entity;
class Player;
class TextureManager;
struct ScreenSize;


struct AppContext {
    float deltaTime{0.0f};
    std::vector<std::unique_ptr<Entity>> entities;
    Player *player{nullptr};
    SDL_Renderer *renderer;
    TextureManager *textureManager;
    ScreenSize screenSize{1920,1080};
};
#endif //DUMRARRIA_APPCONTEXT_H
