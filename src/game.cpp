//
// Created by waylon on 5/24/26.
//

#include "game.h"

#include "player.h"

void Game::initializeGame(AppContext &app) {
    Player player = Player();
    std::unique_ptr<Entity> p_player = std::make_unique<Entity>(player);
    app.entities.push_back(std::move(p_player));
}
