#include "extraExplosionDistance.h"

ExtraExplosionDistance::ExtraExplosionDistance(int& x, int& y)
{
    ExtraExplosionDistance::texture = TextureManager::loadTexture("images/explosionDist.png");
    ExtraExplosionDistance::x = x;
    ExtraExplosionDistance::y = y;
}
bool ExtraExplosionDistance::isDestroyable()
{
    return true;
}
SDL_Texture* ExtraExplosionDistance::getTexture()
{
    return ExtraExplosionDistance::texture;
}
