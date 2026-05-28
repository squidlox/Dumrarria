//
// Created by waylon on 5/21/26.
//

#ifndef DUMRARRIA_PLAYER_H
#define DUMRARRIA_PLAYER_H
#include "EntityClass.h"
#include "globalDataStructs.h"
#include "AppContext.h"
class Player : public Entity {
    private:
    float maxHealth{100};
    float health{73};
    float speed{100};
    void childMove(const AppContext &app, float deltaTime) override;

    public:
    Player();
    Player(Position pos,BoxSize hbs);



    //getters
    [[nodiscard]]float getHealth() const{return this->health;};
    [[nodiscard]] float getMaxHealth() const{return this->maxHealth;};

    //void updateChildren(AppContext &app, float deltaTime)override;



    //setters
    void setHealth(float s_health){this->health = s_health;};
    void setMaxHealth(float s_maxHealth){this->maxHealth = s_maxHealth;};



    ~Player() override = default;
};


#endif //DUMRARRIA_PLAYER_H
