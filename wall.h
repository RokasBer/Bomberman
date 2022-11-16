#ifndef WALL_H_INCLUDED
#define WALL_H_INCLUDED
#include "object.h"

class Wall : public Object
{
    private:
        SDL_Texture* wall;
    public:
        Wall();
        SDL_Texture *getTexture();
};

#endif // WALL_H_INCLUDED
