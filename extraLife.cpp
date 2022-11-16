#include "extraLife.h"
#include "TextureManager.h"

ExtraLife::ExtraLife(int& x, int& y)
{
    ExtraLife::texture = TextureManager::loadTexture("images/life.png");
    ExtraLife::x = x;
    ExtraLife::y = y;
}
bool ExtraLife::isDestroyable()
{
    return true;
}
SDL_Texture* ExtraLife::getTexture()
{
    return ExtraLife::texture;
}
