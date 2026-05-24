//
// Created by waylon on 5/21/26.
//

#ifndef DUMRARRIA_ENTITYCLASSES_H
#define DUMRARRIA_ENTITYCLASSES_H
#include "globalDataStructs.h"

class Entity {
    private:
        Position position{0,0};
         BoxSize hitBoxSize{10,10};
         bool canCollidePriv{false};
    public:
        //constructers
        Entity();
        Entity(float x, float y);
        Entity(float x, float y, bool canCollide);

        //getters
        [[nodiscard]] Position getPosition()const;
        [[nodiscard]] BoxSize getHitBoxSize()const;
        [[nodiscard]] bool canCollide() const;

        //setters
        void setPosition(float x, float y);
        void setPosition(const Position& pos);
        void setHitBoxSize(BoxSize size);
        void setCanCollide(bool canCollide);
};
#endif //DUMRARRIA_ENTITYCLASSES_H