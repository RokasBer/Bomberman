#include "extraBomb.h"
ExtraBomb::ExtraBomb(int& x, int& y)
{
    ExtraBomb::texture = TextureManager::loadTexture("images/extraBomb.png");
    ExtraBomb::x = x;
    ExtraBomb::y = y;
}
bool ExtraBomb::isDestroyable()
{
    return true;
}
SDL_Texture* ExtraBomb::getTexture()
{
    return ExtraBomb::texture;
}
