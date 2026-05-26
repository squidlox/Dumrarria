//
// Created by waylon on 5/25/26.
//
#ifndef DUMRARRIA_USERINTERFACE_H
#define DUMRARRIA_USERINTERFACE_H
#include "globalDataStructs.h"
#include "AppContext.h"
#include "playerClass.h"
#include "SDL3/SDL.h"

class UserInterface {
    BoxSize healthBarBox{500,50};
    Position healthBarPosition{600,800};
public:
    void drawHealthBar(AppContext &appContext);
};
#endif //DUMRARRIA_USERINTERFACE_H
