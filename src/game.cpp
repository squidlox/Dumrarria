//
// Created by waylon on 5/24/26.
//

#include "game.h"
#include "AppContext.h"
#include "player.h"

void Game::initializeGame(AppContext &app) {
    app.entities.push_back(std::make_unique<Player>(Position(10,10), BoxSize(20,20)));
}
void Game::spawnEntity(AppContext &app, Position position, BoxSize boxSize) {
    Entity entity = Entity(position, boxSize);
    std::unique_ptr<Entity> p_entity = std::make_unique<Entity>(entity);
    app.entities.push_back(std::move(p_entity));
}



void Game::updateEntities(AppContext &app) {
    float deltaTime = app.deltaTime;
    for (int i = 0; i < app.entities.size(); i++) {
        app.entities[i]->update(deltaTime);
    }

}