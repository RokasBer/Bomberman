#ifndef EXTRABOMB_H_INCLUDED
#define EXTRABOMB_H_INCLUDED
#include "object.h"
#include "TextureManager.h"

class ExtraBomb: public Object
{
    private:
        SDL_Texture* texture;
    public:
        ExtraBomb(int& x, int& y);
        SDL_Texture *getTexture();
        bool isDestroyable();
};

#endif // EXTRABOMB_H_INCLUDED
