#include "movableObject.h"

bool MovableObject::isDestroyable()
{
    return true;
}

SDL_Texture* MovableObject::getTexture()
{
    return MovableObject::texture;
}
