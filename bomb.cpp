#include "bomb.h"
#include "TextureManager.h"
#include <iostream>
#include <string>
#include <string.h>
#include "player.h"
#include "game.h"
#include <cmath>
#include <vector>
#include "box.h"
#include "object.h"
#include "game.h"
#include "map.h"
#include "extraLife.h"
#include "extraBomb.h"
#include "extraExplosionDistance.h"
#include <math.h>

class Map;
class Game;
Bomb::Bomb(Player *owner, Map *mapp)
{
    isActive = false;
    map = mapp;
    start = 0;
    bombTimer = 5;
    this->owner = owner;
    bombTexture = TextureManager::loadTexture("images/bomb.png");
    srcBomb.x = 0;
    srcBomb.y = 0;
    srcBomb.h = 32;
    srcBomb.w = 32;
    destBomb.x = owner->getXposMap();
    destBomb.y = owner->getYposMap();
    xMapp = owner->getXposMap();
    yMapp = owner->getYposMap();
    explosionTexture = TextureManager::loadTexture("images/boom.png");
    srcExplosion.x = 0;
    srcExplosion.y = 0;
    srcExplosion.h = 64;
    srcExplosion.w = 64;

}

Bomb:: ~Bomb()
{

}

void Bomb::explosion()
{
//    std::vector<Player*> players = Game::getPlayers();
    end = clock();

    if((end - start) / double(CLOCKS_PER_SEC) >= bombTimer)
    {
        SDL_RenderCopy(Game::renderer, explosionTexture, &srcExplosion, &destExplosion);

    }
    if((end - start) / double(CLOCKS_PER_SEC) >= bombTimer +  0.5)
    {
        explode();
        owner->minusActiveBombs();
        isActive = false;
//        std::cout<<"Active bombs:   "<<owner->getActiveBombs()<<std::endl;
    }
}

void Bomb::explode()
{
    int increase = 0;
    std::vector<Player*> players = Game::getPlayers();

    for(int i = 0; i < (int)players.size(); i++)
    {

        if((fabs(players[i]->getXposMap() - getXMapp()) <= owner->getBombExplodeDistance()) && (fabs(players[i]->getYposMap() - getYMapp()) <= owner->getBombExplodeDistance()))
        {

            players[i]->decreaseLives();
        }
    }

    for(int i = getXMapp() - owner->getBombExplodeDistance(); i <= (getXMapp() + owner->getBombExplodeDistance()); i++)
    {
        if(i < 0 || i > 24) continue;
        for(int j = getYMapp() - owner->getBombExplodeDistance(); j <= (getYMapp() + owner->getBombExplodeDistance()); j++)
        {
            if(j < 0 || j > 20) continue;

            if(map->getObject(j,i) != NULL)
            {
                if(map->getObject(j, i)->isDestroyable())
                {

                    if(dynamic_cast<ExtraLife*>(map->getObject(j,i)) != 0)
                    {
                        std::cout<<"life"<<std::endl;
                        owner->setLives(owner->getLives() + 1);
                        std::cout<<"Lives: "<<owner->getLives()<<std::endl;
                        owner->destroyMapObject(map->getObject(j, i)->getY(), map->getObject(j, i)->getX());
                    }
                    else if(dynamic_cast<ExtraBomb*>(map->getObject(j,i)) != 0)
                    {
                        std::cout<<"extrabomb"<<std::endl;
                        owner->operator++();
                        std::cout<<"bombs: "<<owner->getMaxBombs()<<std::endl;
                        owner->destroyMapObject(map->getObject(j, i)->getY(), map->getObject(j, i)->getX());
                    }
                    else if(dynamic_cast<ExtraExplosionDistance*>(map->getObject(j,i)) != 0)
                    {
                        owner->destroyMapObject(map->getObject(j, i)->getY(), map->getObject(j, i)->getX());
                        std::cout<<"distance"<<std::endl;
                        std::cout<<owner->getBombExplodeDistance()<<std::endl;
                        increase = 1;
                        std::cout<<owner->getBombExplodeDistance()<<std::endl;

                    }
                    else
                    owner->destroyMapObject(map->getObject(j, i)->getY(), map->getObject(j, i)->getX());
                }
            }
        }
    }
    if(increase > 0)
    {
        owner->setBombExplodeDistance(owner->getBombExplodeDistance() + 1);
    }

}

void Bomb:: renderBomb()
{
    SDL_RenderCopy(Game::renderer, bombTexture, &srcBomb, &destBomb);
    explosion();
}
void Bomb::setPos(int &x, int &y)
{
    destBomb.x = x+8;
    destBomb.y = y+42;
    destBomb.h = 40;
    destBomb.w = 40;
    destExplosion.h = 70 * owner->getBombExplodeDistance();
    destExplosion.w = 70 * owner->getBombExplodeDistance();
    destExplosion.x = destBomb.x + (destBomb.w/2) - ((double)destExplosion.h/2);
    destExplosion.y = destBomb.y + (destBomb.h/2) - ((double)destExplosion.w/2);
}

void Bomb::setStart()
{
    start = clock();
}
void Bomb::setStart(double &t)
{
    start = t;
}
clock_t Bomb::getStart()const
{
    return start;
}
void Bomb::setEnd()
{
    end = clock();
}
clock_t Bomb::getEnd() const
{
    return end;
}

void Bomb::setBombTimer(double &t)
{
    if(t < 1)
        throw std::invalid_argument("Invalid argument int setBombTimer");
    bombTimer = t;
}
double Bomb::getBombTimer() const
{
    return bombTimer;
}
std::string Bomb::toString() const
{
    std::string temp;
    temp += "bomb timer: " + std::to_string(bombTimer);
    temp += " bomb planted: " + std::to_string(start / double(CLOCKS_PER_SEC)) + '\n';

    return temp;
}
bool Bomb::getIsActive() const
{
    return isActive;
}
void Bomb::setActive()
{
    isActive = true;
}
int Bomb::getXpos() const
{
    return destBomb.x;
}
int Bomb::getYpos() const
{
    return destBomb.y;
}
void Bomb::setmapp(int &x, int &y)
{
    xMapp = x;
    yMapp = y;
}
int Bomb::getXMapp() const
{
    return xMapp;
}

int Bomb::getYMapp() const
{
    return yMapp;
}

