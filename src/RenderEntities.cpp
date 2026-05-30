//
// Created by waylon on 5/21/26.
//
#include "Camera.h"
#include "playerClass.h"
#include "SDL3/SDL.h"
#include <iostream>
#include "SDL3_image/SDL_image.h"

bool DEBUG = true;

void drawEntities(const AppContext &app, SDL_Renderer *renderer, const Camera &camera){

    for (const auto & entity : app.entities) {

        SDL_FRect rect;
        auto [r, g, b, a] = entity->getColor();
        //std::cout << rgba.r << " " << rgba.g << " " << rgba.b << " " << rgba.a << std::endl;
        //todo LERP DIS BITH
        rect.x = entity->getPosition().x - camera.getDrawOffest().x;
        rect.y = entity->getPosition().y - camera.getDrawOffest().y;
        rect.w = entity->getHitBoxSize().width;
        rect.h = entity->getHitBoxSize().height;
        if (app.textureManager == nullptr) {
            std::cout << "this shit null bruh" << std::endl;
        }
        if (entity->hasSprite()) {
            SDL_Texture* texture = app.textureManager->getTexture(app.renderer, entity->getTextureName());
           SDL_RenderTexture(app.renderer,texture , nullptr, &rect);
        }
        else {
            SDL_SetRenderDrawColor(app.renderer, r,g,b,a);
            SDL_RenderFillRect(app.renderer, &rect);
        }
    }
}