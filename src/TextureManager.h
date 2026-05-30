//
// Created by waylon on 5/28/26.
//

#ifndef DUMRARRIA_TEXTUREMANAGER_H
#define DUMRARRIA_TEXTUREMANAGER_H
#include <unordered_map>
#include <vector>
#include <SDL3/SDL.h>
#include "EntityClass.h"

#include "AppContext.h"
#include "globalDataStructs.h"


class TextureManager {
private:

    std::vector<SDL_Texture*> loadedTextures;
    std::unordered_map<TextureName, SDL_Texture*> textureCache;

    std::map<TextureName,std::string> textureLookUp{
        {  PLAYER, "assets/PlayerStatic.png"},
        { ZOMBIE,"assets/PlayerStatic.png"}
    };

    //getpath.
    public:
    SDL_Texture* getTexture(SDL_Renderer *renderer,TextureName textureName);
    //bool loadTextures(AppContext &appContext);

    //load surface

    //load texture
};


#endif //DUMRARRIA_TEXTUREMANAGER_H
