#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED
#include "SDL.h"
class Object
{
    protected:
        SDL_Texture* texture;
        int x;
        int y;
    public:
        virtual bool isDestroyable();
        virtual SDL_Texture *getTexture() = 0;
        virtual int getX();
        virtual int getY();
};


#endif // OBJECT_H_INCLUDED
