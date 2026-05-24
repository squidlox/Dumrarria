//
// Created by waylon on 5/21/26.
//

#ifndef DUMRARRIA_PLAYER_H
#define DUMRARRIA_PLAYER_H
#include "EntityClass.h"
#include "SDL3/SDL.h"

class Player : public Entity {
    private:
    RGBAlpha hitBoxColor{255,255,255,255};
    public:
    Player();
    Player(float x, float y);
    Player(float x, float y, bool canCollide);

    [[nodiscard]]RGBAlpha getHitBoxColor()const;


    void setHitBoxColor(RGBAlpha hitBoxColor);
};


#endif //DUMRARRIA_PLAYER_H
