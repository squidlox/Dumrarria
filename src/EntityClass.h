//
// Created by waylon on 5/21/26.
//


#ifndef DUMRARRIA_ENTITYCLASSES_H
#define DUMRARRIA_ENTITYCLASSES_H

#include "globalDataStructs.h"
#include "AppContext.h"
class AppContext;

class Entity {
    private:
        Position position{0,0};
        BoxSize hitBoxSize{10,10};
        bool canCollidePriv{false};
        RGBAlpha rgba{255,255,255,255};
    public:
        //constructers
        Entity();
        Entity(Position pos,BoxSize hbs);
        Entity(Position, bool canCollide);

        //getters
        [[nodiscard]] RGBAlpha getColor() const;
        [[nodiscard]] Position getPosition()const;
        [[nodiscard]] BoxSize getHitBoxSize()const;
        [[nodiscard]] bool canCollide() const;

        //setters
        void setPosition(float x, float y);
        void setPosition(const Position& pos);
        void setHitBoxSize(BoxSize size);
        void setCanCollide(bool canCollide);
        void setColor(RGBAlpha rgba);

        virtual void update(AppContext &app,float deltaTime);

        //destrucor
        virtual ~Entity();
};
#endif //DUMRARRIA_ENTITYCLASSES_H