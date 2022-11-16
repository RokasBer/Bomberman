#include "player.h"
#include "TextureManager.h"
#include <iostream>
#include <sstream>

Player::Player(const char *textureSheet, const int x, const int y, Map *map)
:xpos(x), ypos(y), maxBombs(startMaxBombs), activeBombs(0), map(map), bombExplodeDistance(startExplodeDistance), lives(1)
{

    setToAlive();
    playerTexture = TextureManager::loadTexture(textureSheet);
    bombCount = TextureManager::loadTexture("images/bombs.png");
    hpTexture = TextureManager::loadTexture("images/hp.png");
    srcBombs.x = srcBombs.y = 0;
    srcBombs.w = srcBombs.h = 16;
    srcHp.x = srcHp.y = 0;
    srcHp.w = srcHp.h = 32;
    destHp.h = destHp.w = destBombs.h = destBombs.w = 20;

    for(int i = 0;i < maxBombs; i++)
    {
        bombs.push_back(new Bomb(this, map));
    }
    xpos = x;
    ypos = y;
    startXpos = xpos;
    xposMap = 1 + (xpos/32);
    yposMap = 1 + (ypos/32);
    if(x > 730 || x < 0)
    {
        setXpos(startXpos1);
        throw std::invalid_argument("Invalid argument x in Player constructor");
    }
    if(y > 600 || y < 0)
    {
        setYpos(startYpos1);
        throw std::invalid_argument("Invalid argument y in Player constructor");
    }

}
Player::Player(const char *textureSheet, const int x, const int y)
:xpos(x), ypos(y), maxBombs(startMaxBombs), activeBombs(0), bombExplodeDistance(startExplodeDistance), lives(1)
{
    setToAlive();
    playerTexture = TextureManager::loadTexture(textureSheet);
    bombCount = TextureManager::loadTexture("images/bombs.png");
    hpTexture = TextureManager::loadTexture("images/hp.png");
    srcBombs.x = srcBombs.y = 0;
    srcBombs.w = srcBombs.h = 16;
    srcHp.x = srcHp.y = 0;
    srcHp.w = srcHp.h = 32;
    destHp.h = destHp.w = destBombs.h = destBombs.w = 20;

    for(int i = 0;i < maxBombs; i++)
    {
        bombs.push_back(new Bomb(this, map));
    }
    xpos = x;
    ypos = y;
    startXpos = xpos;
    xposMap = 1 + (xpos/32);
    yposMap = 1 + (ypos/32);
    if(x > 730 || x < 0)
    {
        setXpos(startXpos1);
        throw std::invalid_argument("Invalid argument x in Player constructor");
    }
    if(y > 600 || y < 0)
    {
        setYpos(startYpos1);
        throw std::invalid_argument("Invalid argument y in Player constructor");
    }
}
Player::~Player()
{

}
void Player:: plantBomb()
{
    if(this->getIsAlive())
    {
        if(activeBombs >= maxBombs)
        {
            return;
        }
        for(int i = 0; i < maxBombs; i++)
        {
            if(!(bombs[i]->getIsActive()))
            {
                bombs[i]->setPos(xpos, ypos);
                bombs[i]->setStart();
                bombs[i]->setActive();
                bombs[i]->setmapp(xposMap, yposMap);
                activeBombs++;
                return;
            }
        }
    }


}
void Player::Update()
{
    srcRect.h = 0;
    srcRect.w = 0;
    srcRect.x = 0;
    srcRect.y = 0;
    destRect.x = xpos;
    destRect.y = ypos;
    destRect.w = 30;
    destRect.h = 30;
//    std::cout<<"VEIKIA"<<std::endl;

}


void Player::Render()
{
//    std::cout<<"VEIKIA"<<std::endl;
    SDL_RenderCopy(Game::renderer, playerTexture, &srcRect, &destRect);
    for(int i = 0; i < lives; i++)
    {
        if(startXpos > 200)
        {
            destHp.x = startXpos - 80 + i*20;
        }
        else
        {
            destHp.x = startXpos - 20 + i*20;
        }

        SDL_RenderCopy(Game::renderer, hpTexture, &srcHp, &destHp);
    }
    for(int i = 0; i < maxBombs; i++)
    {
        if(startXpos > 200)
        {
            destBombs.x = startXpos - 80 + i*20;
        }
        else
        {
            destBombs.x = startXpos - 20 + i*20;
        }
        destBombs.y = 20;
        SDL_RenderCopy(Game::renderer, bombCount, &srcBombs, &destBombs);
    }

    if(activeBombs > 0)
    {
        for(int i = 0; i < maxBombs; i++)
        {
            if(bombs[i]->getIsActive())
            {
                bombs[i]->renderBomb();
            }
        }
    }

}
void Player::minusActiveBombs()
{
        activeBombs--;
        if(activeBombs < 0)
        {
            throw std::runtime_error("Active bombs becomes negative in minusActiveBombs");
        }
}
int Player::getXpos() const
{
    return xpos;
}
int Player::getYpos() const
{
    return ypos;
}
void Player::setXpos(int x)
{
        if(x > 730 || x < 0)
        {
            throw std::invalid_argument("Invalid argument in setXpos");
        }

    xpos = x;
}
void Player::setYpos(int y)
{
        if(y > 600 || y < 0)
        {
            throw std::invalid_argument("Invalid argument in setYpos");
        }

    ypos = y;
}
void Player::setMaxBombs(int x)
{
        if(x < 1)
            throw std::invalid_argument("Invalid argument in setMaxBombs");

    for(int i = bombs.size(); i < x; i++)
    {
        bombs.push_back(new Bomb(this, map));
    }
    maxBombs = x;
}
int Player::getMaxBombs() const
{

    return maxBombs;
}
int Player::getActiveBombs() const
{

    return activeBombs;
}
void Player::destroyPlayerTexture()const
{
    SDL_DestroyTexture(playerTexture);
}
std::string Player::toString() const
{
    std::stringstream ss;
    ss<<name<<" "<<xpos<<";"<<ypos<<" "<<maxBombs<<" "<<activeBombs;
    return ss.str();
}
bool Player::areActiveBombs()
{
    if(activeBombs > 0)
        return true;
    else
        return false;
}
void Player::setName(std::string n)
{
    name = n;
}
std::string Player::getName()const
{
    return name;
}

void Player::increaseMaxBombs()
{
    setMaxBombs(getMaxBombs() + 1);
}

Player& Player::operator ++()
{
    bombs.push_back(new Bomb(this, map));
    maxBombs++;
    return *this;
}
Player& Player::operator +=(int i)
{
    for(int j = 0; j < i; j++)
    bombs.push_back(new Bomb(this, map));
    maxBombs += i;
    return *this;
}
void Player::setToDead()
{
    isAlive = false;
}
void Player::setToAlive()
{
    isAlive = true;
}
bool Player::getIsAlive() const
{
    return isAlive;
}
std::ostream& operator<<(std::ostream& os, const Player &c)
{
    os<<c.toString()<<std::endl;
    return os;
}
std::istream& operator>>(std::istream& is, Player &c)
{
    int x, y, bombs;
    std::string str;
    std::cout<<"Enter players name"<<std::endl;
    is>>str;
    std::cout<<"Enter player's x position"<<std::endl;
    is>>x;

    std::cout<<"Enter player's y position"<<std::endl;
    is>>y;

    std::cout<<"Enter player's max bombs"<<std::endl;
    is>>bombs;
    if(is.fail())
    {
        is.clear();
        is.ignore(256, '\n');
        throw std::invalid_argument("Invalud argurment in >>");
    }
    c.setName(str);
    c.setXpos(x);
    c.setYpos(y);
    c.setMaxBombs(bombs);
    return is;
}
void Player::setXposMap(int x)
{
    xposMap = x;
}

int Player::getXposMap() const
{
    return xposMap;
}
void Player::setYposMap(int y)
{
    yposMap = y;
}
int Player::getYposMap() const
{
    return yposMap;
}
SDL_Texture* Player:: getTexture()
{
    return playerTexture;
}
void Player::destroyMapObject(int x, int y)
{
    map->setMappToNull(x, y);
}
void Player::setBombExplodeDistance(int x)
{
    bombExplodeDistance = x;
}
int Player::getBombExplodeDistance() const
{
    return bombExplodeDistance;
}
int Player::getLives() const
{
    return lives;
}
void Player::setLives(int x)
{
    lives = x;
}
void Player::decreaseLives()
{
    lives--;
}
