//
// Created by waylon on 5/24/26.
//

#ifndef DUMRARRIA_GAME_H
#define DUMRARRIA_GAME_H
#include <SDL3/SDL_render.h>

#include "globalDataStructs.h"
#include "AppContext.h"

class Game {
    public:
        void initializeGame(AppContext &app);
        void spawnEntity(AppContext &app, Position position, BoxSize boxSize);
        void updateEntities(AppContext &app);

        template <typename T>
        void spawn(AppContext &app, Position position, BoxSize boxSize) {
        app.entities.push_back(std::make_unique<T>(position, boxSize));
    }
};


#endif //DUMRARRIA_GAME_H
