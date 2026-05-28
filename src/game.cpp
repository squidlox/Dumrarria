//
// Created by waylon on 5/24/26.
//
#include<iostream>
#include "game.h"
#include "AppContext.h"
#include "EntityClass.h"
#include "playerClass.h"
#include "Enemy.h"
#include "SDL3/SDL_stdinc.h"

using namespace Game;

std::vector<Entity*> collideableEntities;
void Game::initializeGame(AppContext &app) {
    Spawn::spawnPlayer(app, Position(10,10), BoxSize(20,20));
}

void Spawn::spawnEntity(AppContext &app, Position position, BoxSize boxSize, bool canCollide, bool moveable) {
    if (!isSpawnPointValid(app, position, boxSize)) { std::cout <<"INVALID SPAWN LOCATION\n"; return;}
    std::unique_ptr<Entity> up_entity = std::make_unique<Entity>(position, boxSize, canCollide, moveable);
    Entity *p_Entity = up_entity.get();
    if (canCollide == true) {
        collideableEntities.push_back(p_Entity);
    }
    app.entities.push_back(std::move(up_entity));
}
void Spawn::spawnPlayer(AppContext &app, Position position, BoxSize boxSize) {
    if (!isSpawnPointValid(app, position, boxSize)) { std::cout <<"INVALID SPAWN LOCATION"; return;}
    if (app.player == nullptr) {
        std::unique_ptr<Player> up_Player = std::make_unique<Player>(position, boxSize);
        app.entities.push_back(std::move(up_Player));
        auto *p_Player = dynamic_cast<Player *>(app.entities.back().get());
        app.player = p_Player;
    }
    else {
        std::cout << "attempt to spawn player with player already present" << std::endl;
    }
}

void Spawn::spawnEnemy(AppContext &app, Position position, BoxSize boxSize) {
    if (!isSpawnPointValid(app, position, boxSize)) { std::cout <<"INVALID SPAWN LOCATION"; return; }
    std::unique_ptr<Enemy> up_enemy = std::make_unique<Enemy>(position, boxSize);
    Enemy *p_Enemy = up_enemy.get();


    RGBAlpha rgba(SDL_rand(255),SDL_rand(255),SDL_rand(255),255);//NOLINT
    up_enemy->setColor(rgba);
    up_enemy->setSpeed(20);
    collideableEntities.push_back(p_Enemy);
    app.entities.push_back(std::move(up_enemy));
}

bool Spawn::isSpawnPointValid(const AppContext &app, Position position, BoxSize boxSize) {
    BoxSides nextBoxSides{
    nextBoxSides.top = position.y, nextBoxSides.bottom = position.y + boxSize.height,
    nextBoxSides.left = position.x, nextBoxSides.right = position.x + boxSize.width};

    for (const auto& entityPtr : app.entities) {
        if (entityPtr->canCollide() == false) {
            continue;
        }
        BoxSides indexEntitySides = entityPtr->getBoxSides();
        if (nextBoxSides.top < indexEntitySides.bottom && nextBoxSides.bottom > indexEntitySides.top &&
            nextBoxSides.left < indexEntitySides.right && nextBoxSides.right > indexEntitySides.left) {
            return false;
            }
    }
    return true;
}

void Game::updateEntities(const AppContext &app) {
    float deltaTime = app.deltaTime;
    for (int i = 0; i < app.entities.size(); i++) {
        app.entities[i]->update(app,deltaTime);
    }
}