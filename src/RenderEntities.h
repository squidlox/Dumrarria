//
// Created by waylon on 5/21/26.
//

#ifndef DUMRARRIA_RENDERENTITIES_H
#define DUMRARRIA_RENDERENTITIES_H
#include <SDL3/SDL.h>
#include "Camera.h"

void drawEntities(const AppContext &app,SDL_Renderer *renderer,const Camera &camera);
#endif //DUMRARRIA_RENDERENTITIES_H
