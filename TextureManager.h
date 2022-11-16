#ifndef TEXTUREMANAGER_H_INCLUDED
#define TEXTUREMANAGER_H_INCLUDED
#include "game.h"
///Class responsible for textures, loading and drawing
class TextureManager
{
    public:
        ///Loads texture into game
        static SDL_Texture *loadTexture(const char* fileName);
        ///Draws texture into game's window
        static void Draw(SDL_Texture *tex, SDL_Rect src, SDL_Rect dest);
};


#endif // TEXTUREMANAGER_H_INCLUDED
