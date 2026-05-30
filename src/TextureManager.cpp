//
// Created by waylon on 5/28/26.
//

#include "TextureManager.h"

#include <iostream>

#include "SDL3_image/SDL_image.h"

SDL_Texture* TextureManager::getTexture(SDL_Renderer *renderer,TextureName textureName) {

    //check is texture is already loaded in the cache

    auto cachedTexture = textureCache.find(textureName);

    if (cachedTexture != textureCache.end()) {
        return cachedTexture->second;
    }



    //find path in texturelookup map if not already loaded
    auto texturePath = textureLookUp.find(textureName);
    if (texturePath == textureLookUp.end()) {
        std::cerr <<"TextureManager Error, no such path exists" << std::endl;
        return nullptr;
    }

    std::string fullPath = SDL_GetBasePath() + texturePath->second;
    SDL_Surface *tempSurface = SDL_LoadPNG(fullPath.c_str());

    if (!tempSurface) {
        std::cerr << "TextureManager: Failed to load disk file: " << fullPath
                  << " | SDL_Error: " << SDL_GetError() << std::endl;
        return nullptr;
    }

    SDL_Texture * newTexture = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_DestroySurface(tempSurface);

    if (!newTexture) {
        std::cerr << "TextureManager: Failed to create GPU texture for: " << std::endl;
        return nullptr;
    }

    textureCache[textureName] = newTexture;
    return newTexture;
}

