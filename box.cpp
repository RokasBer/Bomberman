#include "TextureManager.h"
#include "box.h"

SDL_Texture* Box::getTexture()
{
    return Box::texture;
}

Box::Box(int &x, int &y)
{
    Box::texture = TextureManager::loadTexture("images/block.png");
    Box::x = x;
    Box::y = y;
}
bool Box::isDestroyable()
{
    return true;
}
