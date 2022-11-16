#include "map.h"
#include "TextureManager.h"
#include <string.h>
#include "wall.h"
#include "box.h"
#include <iostream>
#include "game.h"
#include "extraLife.h"
#include "extraBomb.h"
#include "extraExplosionDistance.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>
int lvl1[21][25] =
{
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
    {1,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
    {1,0,0,0,0,0,2,0,2,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
    {1,0,0,0,0,0,2,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
    {1,0,0,0,2,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

Map::Map()
{
    path = TextureManager::loadTexture("images/path.png");

    mapName = "default";
    for(int i = 0; i < 21; i++)
    {
        for(int j = 0; j < 25; j++)
        {
            mapp[i][j] = NULL;
        }
    }

    randomGenerator(lvl1);
    loadMap(lvl1);


    src.x = src.y = 0;
    src.w = dest.w = 32;
    src.h = dest.h = 32;
    dest.x = dest.y = 0;

}
Map::~Map()
{
    for(int row = 0; row < 21; row++)
    {
        for(int column = 0; column < 25; column++)
        {
            if(mapp[row][column] != nullptr)
            {
                delete mapp[row][column];
            }
        }
    }
}
void Map::loadMap(int arr[21][25])
{

    int type = 0;
    for(int row = 0; row < 21; row++)
    {
        for(int column = 0; column < 25; column++)
        {
            type = arr[row][column];

            switch(type)
            {
            case 0:
                break;
            case 2:
                mapp[row][column] = new Box(column, row);
                break;

            case 1:
                mapp[row][column] = new Wall;
                break;
            case 3:
                mapp[row][column] = new ExtraLife(column, row);
                break;
            case 4:
                 mapp[row][column] = new ExtraBomb(column, row);
                 break;
            case 5:
                mapp[row][column] = new ExtraExplosionDistance(column, row);
                break;
            default:
                break;
            }
        }
    }
}

void Map::drawMap()
{
    int type;
    for(int row = 0; row < 21; row++)
    {
        for(int column = 0; column < 25; column++)
        {
            type = 0;
            if(mapp[row][column] != NULL)
            {
                type = 1;
            }

            dest.x = column * 32;
            dest.y = 32 + row * 32;

            switch(type)
            {
            case 0:
                TextureManager::Draw(path, src, dest);
                break;
            case 1:
                TextureManager::Draw(mapp[row][column]->getTexture(), src, dest);
                break;

            default:
                break;
            }
        }
    }

}
std::string Map::getMapName()
{
    return mapName;
}
void Map::setMapName(std::string& n)
{
    mapName = n;
}
void Map::setMappToNull(int x, int y)
{
    mapp[x][y] = NULL;
}
void Map::setMapObject(int x, int y, Object *obj)
{
    mapp[x][y] = obj;
}
Object* Map::getObject(int x, int y)
{
    return mapp[x][y];
}
void Map::randomGenerator(int arr[21][25])
{
    int ro, col, powerup, powerUps = 0, boxes = 0, explodeDistLimit = 0;
    srand(time(NULL));
    while(powerUps < powerUpLimit)
    {
        ro = 2 + rand() % 17;
        col = 2 + rand() % 21;
        powerup = 3 + (rand() % 3);

        if((powerup == 5) && (explodeDistLimit > 2))
        {
            continue;
        }
        if(arr[ro][col] == 0)
        {
            arr[ro][col] = powerup;
            if(powerup == 5)
            {
                explodeDistLimit++;
            }
            powerUps++;
        }
    }
    while(boxes < 70)
    {
        ro = 2 + rand() % 17;
        col = 2 + rand() % 21;
        if(arr[ro][col] == 0)
        {
            arr[ro][col] = 2;
            boxes++;
        }
    }
}
