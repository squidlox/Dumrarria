//
// Created by waylon on 5/24/26.
//

#ifndef DUMRARRIA_GAME_H
#define DUMRARRIA_GAME_H

#include "globalDataStructs.h"
#include "AppContext.h"

namespace Game {
        void initializeGame(AppContext &app);
        void updateEntities(const AppContext &app);
        //spawning functions
        namespace Spawn {
                void spawnEntity(AppContext &app, Position position, BoxSize boxSize, bool canCollide, bool moveable);
                void spawnPlayer(AppContext &app, Position position, BoxSize boxSize);
                void spawnEnemy(AppContext &app, Position position, BoxSize boxSize);
        }
};


#endif //DUMRARRIA_GAME_H
