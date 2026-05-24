//
// Created by waylon on 5/24/26.
//
#ifndef DUMRARRIA_INPUTHANDLER_H
#define DUMRARRIA_INPUTHANDLER_H
#include <iostream>
#include <map>
#include <ostream>

#include "SDL3/SDL.h"
#include "globalDataStructs.h"

enum InputState {
  UP,
  DOWN,
  LEFT,
  RIGHT
};

class InputHandler {
  private:
      static inline std::map<InputState, SDL_Scancode> keyMap =
    {
        {UP, SDL_SCANCODE_W},
        {DOWN, SDL_SCANCODE_S},
        {LEFT, SDL_SCANCODE_A},
        {RIGHT, SDL_SCANCODE_D},
    };
  public:
  InputHandler();
  ~InputHandler();

  static VelocityVector getInputDirection();
};
#endif //DUMRARRIA_INPUTHANDLER_H
