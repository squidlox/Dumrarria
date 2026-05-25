//
// Created by waylon on 5/24/26.
//

#ifndef DUMRARRIA_APPCONTEXT_H
#define DUMRARRIA_APPCONTEXT_H

class Entity;
class Player;

struct AppContext {
    float deltaTime{0.0f};
    std::vector<std::unique_ptr<Entity>> entities;

    Player* player = nullptr;
};




#endif //DUMRARRIA_APPCONTEXT_H
