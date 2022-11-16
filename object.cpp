#include "object.h"
#include "TextureManager.h"
bool Object::isDestroyable()
{
    return false;
}
SDL_Texture* Object::getTexture()
{
    return Object::texture;
}
int Object::getX()
{
    return Object::x;
}
int Object::getY()
{
    return Object::y;
}
