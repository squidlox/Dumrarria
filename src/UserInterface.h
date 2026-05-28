//
// Created by waylon on 5/25/26.
//
#ifndef DUMRARRIA_USERINTERFACE_H
#define DUMRARRIA_USERINTERFACE_H
#include "globalDataStructs.h"
#include "AppContext.h"

class UserInterface {
    BoxSize healthBarBox{500,50};
    Position healthBarPosition{600,800};
public:
    void drawHealthBar(const AppContext &appContext) const;
};
#endif //DUMRARRIA_USERINTERFACE_H
