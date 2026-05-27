//
// Created by waylon on 5/24/26.
//
#ifndef DUMRARRIA_ENEMY_H
#define DUMRARRIA_ENEMY_H

#include "EntityClass.h"

class Enemy : public Entity {
private:
    float speed{75};
    RGBAlpha hitBoxColor{0,255,0,0};
public:
    Enemy();
    Enemy(Position pos,BoxSize hbs);

    //getters
    [[nodiscard]]RGBAlpha getHitBoxColor()const;

    void update(AppContext& app, float deltaTime) override;

    //setters
    void setHitBoxColor(RGBAlpha hitBoxColor);

    ~Enemy() override = default;
};
#endif //DUMRARRIA_ENEMY_H
