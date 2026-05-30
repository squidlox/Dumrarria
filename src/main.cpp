#define SDL_MAIN_USE_CALLBACKS 1  /* use the callbacks instead of main() */
#include <iostream>
#include <vector>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include  "InputHandler.h"
#include "globalDataStructs.h"
#include "game.h"
#include "RenderEntities.h"
#include "AppContext.h"
#include "Camera.h"
#include "playerClass.h"//NOLINT
#include "UserInterface.h"

//setup variables for initializaiton
static SDL_Window *window = nullptr;
static SDL_Renderer *renderer = nullptr;

UserInterface userInterface;
Camera camera;
ScreenSize screenSize;

//setup delta time
static Uint64 lastTimeMs = 0;

//SDl APP INTIT RUNS ONCE WHEN USING CALLBACKS. AND RETURNS A VALUE OF TYPE SDL_AppResult
SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[])
{
    SDL_srand(1);
    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        SDL_Log("SDL_Init() failed: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }
    //check for users display size and default to 1920x1080 if not found
    SDL_Rect screen;
    screen.w = screenSize.width;
    screen.h = screenSize.height;
    const SDL_DisplayID displayId = SDL_GetPrimaryDisplay();

    if (!SDL_GetDisplayBounds(displayId, &screen) && displayId != 0) {
        std::cerr << "SDL_GetDisplayBounds() failed: " << SDL_GetError() << std::endl;
        return SDL_APP_FAILURE;
    }
    else {
        screenSize.width = screen.w;
        screenSize.height = screen.h;
    }

    if (!SDL_CreateWindowAndRenderer("First SDL Window", screenSize.width, screenSize.height, SDL_WINDOW_RESIZABLE, &window, &renderer)) {
        SDL_Log("SDL_CreateWindowAndRenderer() failed: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }



    //initialize game and appContext
    
    auto* context = new AppContext();
    *appstate = context;
    context->renderer = renderer;
    context->screenSize = screenSize;
    context->textureManager = new TextureManager();
    Game::initializeGame(*context);
    lastTimeMs = SDL_GetTicks();

    SDL_SetRenderLogicalPresentation(context->renderer,screenSize.width, screenSize.height, SDL_LOGICAL_PRESENTATION_STRETCH);

    return SDL_APP_CONTINUE;
}

//this function will set up event handling and returns an ADL_AppResult
SDL_AppResult SDL_AppEvent(void *app, SDL_Event *event)
{
    auto *context = static_cast<AppContext *>(app);
    if (event->type == SDL_EVENT_QUIT ) {
        return SDL_APP_SUCCESS;
    }
    if (event->type == SDL_EVENT_WINDOW_RESIZED) {
        SDL_SetRenderViewport(context->renderer,nullptr);
    }
    if (event->type == SDL_EVENT_KEY_UP) {
        if (event->key.scancode == SDL_SCANCODE_EQUALS) {

            Position position(SDL_rand(1920),SDL_rand(1080));//NOLINT
            BoxSize size {20,20};
            Game::Spawn::spawnEnemy(*context,position,size);
        }
        if (event->key.scancode == SDL_SCANCODE_U) {
            for (int i = 0; i <100; i++) {
                Position position(SDL_rand(1920) + camera.getDrawOffest().x,SDL_rand(1080)+ camera.getDrawOffest().y);//NOLINT
                BoxSize size {20,20};
                Game::Spawn::spawnEnemy(*context,position,size);
            }
        }
        if (event->key.scancode == SDL_SCANCODE_P) {
            std::cout << "Frame Time: " << context->deltaTime * 1000.0 << " ms\n"
          << "FPS: " << static_cast<int>(1.0 / context->deltaTime) << '\n'
          << "Entities spawned: " << context->entities.size() << '\n';
        }
    }
    return SDL_APP_CONTINUE;
}

//SDL's VERSION OF MAIN FUNCTION
SDL_AppResult SDL_AppIterate(void *appstate)
{
    //calculate deltatime
    auto* context = static_cast<AppContext*>(appstate);
    Uint64 currentTimeMs = SDL_GetTicks();
    Uint64 elapsedMs = currentTimeMs - lastTimeMs;
    lastTimeMs = currentTimeMs;
    context->deltaTime = static_cast<float>(elapsedMs)/1000.0f;

    //testing stuff
    InputHandler::devChangeHealth(*context);

    //update camera before rendering
    camera.update(*context);
    //render the screen
    SDL_SetRenderDrawColor(context->renderer,20,20,20,255);
    SDL_RenderClear(context->renderer);
    drawEntities(*context,context->renderer,camera);
    userInterface.drawHealthBar(*context);
    SDL_RenderPresent(context->renderer);
    Game::updateEntities(*context);
    return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void *appstate, SDL_AppResult result)
{
    auto *context = static_cast<AppContext *>(appstate);
    if (context->renderer) {
        SDL_DestroyRenderer(context->renderer);
    }
    if (appstate) {
        delete context;
    }
    if (window) {
        SDL_DestroyWindow(window);
    }
}