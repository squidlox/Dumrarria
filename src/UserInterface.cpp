//
// Created by waylon on 5/25/26.
//
#include "UserInterface.h"
#include "playerClass.h"
#include "SDL3/SDL.h"


void  UserInterface::drawHealthBar(const AppContext &appContext) const{
    Player* player =  appContext.player;
    SDL_FRect rectGreenHealth;
    rectGreenHealth.w = healthBarBox.width;
    rectGreenHealth.h = healthBarBox.height;
    rectGreenHealth.x = (static_cast<float>(appContext.screenSize.width) / 2.0f - rectGreenHealth.w / 2.0f);
    rectGreenHealth.y = static_cast<float>(appContext.screenSize.height) * 0.9f;;
    SDL_FRect rectRedHealth = rectGreenHealth;

    if (player->getHealth() >= 0) {

        SDL_SetRenderDrawColor(appContext.renderer,255,0,0,255);
        SDL_RenderFillRect(appContext.renderer, &rectRedHealth);


        float percentRemaining = player->getHealth()/player->getMaxHealth();

        rectGreenHealth.w *= percentRemaining;
        SDL_SetRenderDrawColor(appContext.renderer,0,255,0,255);
        SDL_RenderFillRect(appContext.renderer, &rectGreenHealth);
    }
    else {
        SDL_SetRenderDrawColor(appContext.renderer,255,0,0,255);
        SDL_RenderFillRect(appContext.renderer, &rectRedHealth);
    }

}