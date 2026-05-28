//
// Created by waylon on 5/24/26.
//
#ifndef DUMRARRIA_INPUTHANDLER_H
#define DUMRARRIA_INPUTHANDLER_H
#include <map>
#include "SDL3/SDL.h"
#include "globalDataStructs.h"
#include "AppContext.h"

enum InputState {
  UP,
  DOWN,
  LEFT,
  RIGHT,
  ADDHEALTH,
  REMOVEHEALTH,
};
class Player;
class InputHandler {
  private:
      static inline std::map<InputState, SDL_Scancode> keyMap =
    {
        {UP, SDL_SCANCODE_W},
        {DOWN, SDL_SCANCODE_S},
        {LEFT, SDL_SCANCODE_A},
        {RIGHT, SDL_SCANCODE_D},
        {ADDHEALTH, SDL_SCANCODE_EQUALS},
        {REMOVEHEALTH, SDL_SCANCODE_MINUS}
    };
  public:

    static VelocityVector getInputDirection();
    static void devChangeHealth(const AppContext &app);
};
#endif //DUMRARRIA_INPUTHANDLER_H
