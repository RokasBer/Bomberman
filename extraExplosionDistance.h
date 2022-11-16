#ifndef EXTRAEXPLODEDISTANCE_H_INCLUDED
#define EXTRAEXPLODEDISTANCE_H_INCLUDED
#include "object.h"
#include "TextureManager.h"
class ExtraExplosionDistance: public Object
{
    private:
        SDL_Texture* texture;
    public:
        ExtraExplosionDistance(int& x, int& y);
        SDL_Texture *getTexture();
        bool isDestroyable();
};


#endif // EXTRAEXPLODEDISTANCE_H_INCLUDED
