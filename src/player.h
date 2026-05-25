//
// Created by waylon on 5/21/26.
//

#ifndef DUMRARRIA_PLAYER_H
#define DUMRARRIA_PLAYER_H
#include "EntityClass.h"
#include "InputHandler.h"
#include "globalDataStructs.h"
#include "SDL3/SDL.h"

class Player : public Entity {
    private:
    float speed{0.01};
    RGBAlpha hitBoxColor{255,255,255,255};
    public:
    Player();
    Player(Position pos,BoxSize hbs);
    Player(Position pos, bool canCollide);

    //getters
    [[nodiscard]]RGBAlpha getHitBoxColor()const;

    void update(float deltaTime) override;

    //setters
    void setHitBoxColor(RGBAlpha hitBoxColor);

    ~Player() override = default;
};


#endif //DUMRARRIA_PLAYER_H
