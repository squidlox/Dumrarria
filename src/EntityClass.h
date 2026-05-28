//
// Created by waylon on 5/21/26.
//


#ifndef DUMRARRIA_ENTITYCLASSES_H
#define DUMRARRIA_ENTITYCLASSES_H

#include "globalDataStructs.h"
#include "AppContext.h"

struct AppContext;

class Entity {
    private:
        Position position{0,0};
        BoxSize hitBoxSize{10,10};
        BoxSides boxSides{0,0,0,0};
        RGBAlpha rgba{255,255,255,255};


        //variables for collission
        bool canCollidePriv{false};
        bool isMoveablePriv{false};
        float remainingMovementX{0.0f};
        float remainingMovementY{0.0f};

    public:
        //constructers
        Entity();
        Entity(Position pos, BoxSize hbs, bool canCollide, bool moveable);

        //getters
        [[nodiscard]] RGBAlpha getColor() const;
        [[nodiscard]] Position getPosition()const;
        [[nodiscard]] BoxSize getHitBoxSize()const;
        [[nodiscard]] BoxSides getBoxSides();
        [[nodiscard]] bool isMoveable()const;
        [[nodiscard]] bool canCollide() const;


        //setters
        void setPosition(float x, float y);
        void setPosition(const Position& pos);
        void setHitBoxSize(BoxSize size);
        void setCanCollide(bool canCollide);
        void setIsMoveable(bool moveable);
        void setColor(RGBAlpha rgba);

        void update(const AppContext &app,float deltaTime);

        //movement functions
        void attemptMovement(const AppContext &app,float dirX, float dirY);
    private:

        void attemptMovementX(const AppContext &app,float dirX);
        void attemptMovementY(const AppContext &app,float dirY);
        virtual void updateChildren(const AppContext& app, float deltaTime);
        virtual void childMove(const AppContext &app, float deltaTime);
        [[nodiscard]] bool checkCollision(const AppContext &app,Position nextPosition) const;

    public:

        //destrucor
        virtual ~Entity();
};
#endif //DUMRARRIA_ENTITYCLASSES_H