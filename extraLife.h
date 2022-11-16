#ifndef EXTRALIFE_H_INCLUDED
#define EXTRALIFE_H_INCLUDED
#include "object.h"
class ExtraLife: public Object
{
    private:
        SDL_Texture* texture;
    public:
        ExtraLife(int& x, int& y);
        SDL_Texture *getTexture();
        bool isDestroyable();
};


#endif // EXTRALIFE_H_INCLUDED
