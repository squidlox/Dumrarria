//
// Created by waylon on 5/24/26.
//

#include "game.h"
#include "AppContext.h"
#include "EntityClass.h"
#include "playerClass.h"
#include "Enemy.h"
#include "SDL3/SDL_stdinc.h"

std::vector<Entity*> collidableEntities;
void Game::initializeGame(AppContext &app) {
    spawnPlayer(app, Position(10,10), BoxSize(20,20));
}

void Game::spawnEntity(AppContext &app, Position position, BoxSize boxSize, bool canCollide, bool moveable) {
    std::unique_ptr<Entity> up_entity = std::make_unique<Entity>(position, boxSize, canCollide, moveable);
    Entity *p_Entity = up_entity.get();
    if (canCollide == true) {
        collidableEntities.push_back(p_Entity);
    }
    app.entities.push_back(std::move(up_entity));

}
void Game::spawnPlayer(AppContext &app, Position position, BoxSize boxSize) {
    if (app.player == nullptr) {
        std::unique_ptr<Player> up_Player = std::make_unique<Player>(position, boxSize);
        Player *p_Player = up_Player.get();
        app.player = p_Player;
        collidableEntities.push_back(p_Player);
        app.entities.push_back(std::move(up_Player));
    }
    else {
        std::cout << "attempt to spawn player with player already present" << std::endl;
    }
}

void Game::spawnEnemy(AppContext &app, Position position, BoxSize boxSize) {

    std::unique_ptr<Enemy> up_enemy = std::make_unique<Enemy>(position, boxSize);
    Enemy *p_Enemy = up_enemy.get();

    RGBAlpha rgba = RGBAlpha(SDL_rand(255),SDL_rand(255),SDL_rand(255),255);
    up_enemy->setColor(rgba);
    up_enemy->setSpeed(20);
    collidableEntities.push_back(p_Enemy);
    app.entities.push_back(std::move(up_enemy));
}

void Game::updateEntities(AppContext &app) {
    float deltaTime = app.deltaTime;
    for (int i = 0; i < app.entities.size(); i++) {
        app.entities[i]->update(app,deltaTime);
    }
}