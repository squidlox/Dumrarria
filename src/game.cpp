//
// Created by waylon on 5/24/26.
//

#include "game.h"
#include "AppContext.h"
#include "EntityClass.h"
#include "playerClass.h"
#include "Enemy.h"
#include "SDL3/SDL_stdinc.h"

std::vector<std::unique_ptr<Entity>> collidableEntities;
void Game::initializeGame(AppContext &app) {
    spawnPlayer(app, Position(10,10), BoxSize(20,20));



    std::cout<< app.entities.size() << " entities created" << std::endl;
}
void Game::spawnEntity(AppContext &app, Position position, BoxSize boxSize, bool canCollide, bool moveable) {
    Entity entity = Entity(position, boxSize, canCollide, moveable);
    std::unique_ptr<Entity> p_entity = std::make_unique<Entity>(entity);
    app.entities.push_back(std::move(p_entity));
    if (canCollide == true) {
        collidableEntities.push_back(std::move(p_entity));
        std::cout<< "cancollide true" << std::endl;
    }
}
void Game::spawnPlayer(AppContext &app, Position position, BoxSize boxSize) {
    if (app.player == nullptr) {
        Player player = Player(position, boxSize);
        std::unique_ptr<Player> p_Player = std::make_unique<Player>(player);
        app.player = p_Player.get();
        std::cout << app.player << std::endl;
        app.entities.push_back(std::move(p_Player));
        collidableEntities.push_back(std::move(p_Player));
    }
    else {
        std::cout << "attempt to spawn player with player already present" << std::endl;
    }
}

void Game::spawnEnemy(AppContext &app, Position position, BoxSize boxSize) {
    Enemy enemy = Enemy(position, boxSize);
    enemy.setHitBoxColor(RGBAlpha((255), SDL_rand(255), SDL_rand(255), 255));
    std::unique_ptr<Enemy> p_enemy = std::make_unique<Enemy>(enemy);
    app.entities.push_back(std::move(p_enemy));
    collidableEntities.push_back(std::move(p_enemy));
}

void Game::updateEntities(AppContext &app) {
    float deltaTime = app.deltaTime;
    for (int i = 0; i < app.entities.size(); i++) {
        app.entities[i]->update(app,deltaTime);
    }
}