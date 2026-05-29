//
// Created by waylon on 5/21/26.
//
#include "Camera.h"
#include "playerClass.h"
#include "SDL3/SDL.h"

bool DEBUG = true;

void drawEntities(const AppContext &app, SDL_Renderer *renderer, const Camera &camera){

    for (const auto & entity : app.entities) {
        SDL_FRect rect;
        auto [r, g, b, a] = entity->getColor();
        //std::cout << rgba.r << " " << rgba.g << " " << rgba.b << " " << rgba.a << std::endl;
        rect.x = entity->getPosition().x - camera.getDrawOffest().x;
        rect.y = entity->getPosition().y - camera.getDrawOffest().y;
        rect.w = entity->getHitBoxSize().width;
        rect.h = entity->getHitBoxSize().height;
        SDL_SetRenderDrawColor(renderer, r,g,b,a);
        SDL_RenderFillRect(renderer, &rect);
    }
    if (DEBUG == true) {
        std::string test = "test debug text";
        SDL_SetRenderDrawColor(renderer, 0,255,255,255);
        SDL_RenderDebugText(renderer, camera.getDrawOffest().x, camera.getDrawOffest().y, test.c_str());
    }
}