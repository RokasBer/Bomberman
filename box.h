#ifndef BOX_H_INCLUDED
#define BOX_H_INCLUDED
#include "object.h"

class Box : public Object
{
    private:
        SDL_Texture* texture;
    public:
        Box(int &x, int &y);
        SDL_Texture *getTexture();
        bool isDestroyable();
};


#endif // BOX_H_INCLUDED
