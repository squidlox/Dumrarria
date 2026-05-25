//
// Created by waylon on 5/21/26.
//

#ifndef DUMRARRIA_PLAYER_H
#define DUMRARRIA_PLAYER_H
#include "EntityClass.h"
#include "InputHandler.h"
#include "globalDataStructs.h"
#include "AppContext.h"
#include "SDL3/SDL.h"

class Player : public Entity {
    private:
    float speed{100};
    public:
    Player();
    Player(Position pos,BoxSize hbs);
    Player(Position pos, bool canCollide);

    //getters


    void update(AppContext& app, float deltaTime) override;

    //setters

    ~Player() override = default;
};


#endif //DUMRARRIA_PLAYER_H
