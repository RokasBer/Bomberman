#include "wall.h"
#include "TextureManager.h"

Wall::Wall()
{
    Wall::texture = TextureManager::loadTexture("images/wall.png");
}
SDL_Texture* Wall::getTexture()
{
    return Wall::texture;
}
