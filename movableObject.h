#ifndef MOVABLEOBJECT_H_INCLUDED
#define MOVABLEOBJECT_H_INCLUDED
#include "TextureManager.h"
class MovableObject: public Object
{
    protected:
        SDL_Texture* texture;

    public:
        virtual bool isDestroyable();
        virtual SDL_Texture *getTexture();
};


#endif // MOVABLEOBJECT_H_INCLUDED
