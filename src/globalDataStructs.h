//
// Created by waylon on 5/21/26.
//
#ifndef DUMRARRIA_GLOBALDATASTRUCTS_H
#define DUMRARRIA_GLOBALDATASTRUCTS_H
#include <memory>
#include <vector>

class Entity;

struct AppContext {
    float deltaTime{0.0f};
    std::vector<std::unique_ptr<Entity>> entities;
};

struct ScreenSize {
    int width{0};
    int height{0};
};
struct Position {
    float x{0};
    float y{0};
};
struct BoxSize {
    float width{0};
    float height{0};
};
struct RGBAlpha {
    float r{0};
    float g{0};
    float b{0};
    float a{0};
};

#endif //DUMRARRIA_GLOBALDATASTRUCTS_H