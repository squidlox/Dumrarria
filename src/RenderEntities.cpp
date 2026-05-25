//
// Created by waylon on 5/21/26.
//
#include "playerClass.h"
#include "SDL3/SDL.h"
void drawEntities(SDL_Renderer *renderer, const std::vector<std::unique_ptr<Entity>>& entities){
    for (int i=0; i<entities.size(); i++) {
        SDL_FRect rect;
        RGBAlpha rgba = entities[i]->getColor();
        rect.x = entities[i]->getPosition().x;
        rect.y = entities[i]->getPosition().y;
        rect.w = entities[i]->getHitBoxSize().width;
        rect.h = entities[i]->getHitBoxSize().height;
        SDL_SetRenderDrawColor(renderer, rgba.r,rgba.g,rgba.b,rgba.a);
        SDL_RenderFillRect(renderer, &rect);
    }
}