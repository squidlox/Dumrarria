//
// Created by waylon on 5/21/26.
//

#ifndef DUMRARRIA_PLAYER_H
#define DUMRARRIA_PLAYER_H
#include "EntityClass.h"
#include "globalDataStructs.h"
#include "AppContext.h"
#include "cmath"
#include "InputHandler.h"
class Player : public Entity {
    private:
    float maxHealth{100};
    float health{73};
    float speed{100};

    public:
    Player();
    Player(Position pos,BoxSize hbs);



    //getters
    [[nodiscard]]float getHealth() const{return this->health;};
    [[nodiscard]] float getMaxHealth() const{return this->maxHealth;};

    void update(AppContext& app, float deltaTime) override;
    void attemptMovementX(float requestedMovement);
    void attemptMovementY(float requestedMovement);

    //setters
    void setHealth(float health){this->health = health;};
    void setMaxHealth(float maxHealth){this->maxHealth = maxHealth;};



    ~Player() override = default;
};


#endif //DUMRARRIA_PLAYER_H
