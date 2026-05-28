//
// Created by waylon on 5/21/26.
//
#include "playerClass.h"
#include "SDL3/SDL.h"
void drawEntities(SDL_Renderer *renderer, const std::vector<std::unique_ptr<Entity>>& entities){
    for (const auto & entity : entities) {
        SDL_FRect rect;
        auto [r, g, b, a] = entity->getColor();
        //std::cout << rgba.r << " " << rgba.g << " " << rgba.b << " " << rgba.a << std::endl;
        rect.x = entity->getPosition().x;
        rect.y = entity->getPosition().y;
        rect.w = entity->getHitBoxSize().width;
        rect.h = entity->getHitBoxSize().height;
        SDL_SetRenderDrawColor(renderer, r,g,b,a);
        SDL_RenderFillRect(renderer, &rect);
    }
}