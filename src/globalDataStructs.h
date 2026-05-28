//
// Created by waylon on 5/21/26.
//
#ifndef DUMRARRIA_GLOBALDATASTRUCTS_H
#define DUMRARRIA_GLOBALDATASTRUCTS_H
#include <SDL3/SDL_stdinc.h>

struct ScreenSize {
    int width{0};
    int height{0};
};
struct VelocityVector {
    float x{0};
    float y{0};
};
struct Position {
    float x{0};
    float y{0};
};
struct BoxSize {
    float width{0};
    float height{0};
};
struct BoxSides {
    float top{0};
    float bottom{0};
    float left{0};
    float right{0};
};
struct RGBAlpha {
    Uint8 r{0};
    Uint8 g{0};
    Uint8 b{0};
    Uint8 a{0};
};
#endif //DUMRARRIA_GLOBALDATASTRUCTS_H