#include "game.h"
#include <iostream>
#include "TextureManager.h"
#include "player.h"
#include "map.h"
#include "bomb.h"
#include<fstream>
#include <vector>
#include <unistd.h>
#include <windows.h>
#include "box.h"
//std::vector <Player*> players;

Player *enemy;
SDL_Renderer *Game::renderer = nullptr;
Map *Game::map = nullptr;
SDL_Event Game:: event;
std::vector<Player*> Game::players;
const int yVelocity = 32;
const int xVelocity = 32;
Game :: Game()
{

}
Game :: ~Game()
{
//    delete players;
}
void Game :: init (const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;
    if(fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;

    }
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std:: cout<<"Subsystems initialized"<<std::endl;
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

        if(window)
        {
            std::cout<<"Window created"<<std::endl;
        }
        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255 ,255, 255);
            std::cout<<"Renderer created"<<std::endl;
        }
        isRunning = true;
    }
    else
    {
        isRunning = false;
    }
        map = new Map();
        players.push_back(new Player("images/player.png", 22, 22, map));
        players.push_back(new Player("images/enemy.png", 726, 598, map));
        map->setMapObject(players[0]->getYposMap(), players[0]->getXposMap(), players[0]);
        map->setMapObject(players[1]->getYposMap(), players[1]->getXposMap(), players[1]);



//        for(int i = 0; i < 21; i ++)
//            {
//                for(int k = 0; k < 25; ++k)
//                {
//                    if(map->mapp[i][k] != NULL)
//                    {
//                        std::cout<<"*";
//                    }
//                    else
//                    {
//                        std::cout<< "0";
//                    }
//
//                }
//                std::cout<<std::endl;
//            }
//            std::cout<<std::endl;


        map->setMapObject(players[0]->getXposMap(), players[0]->getYposMap(), players[0]);
        map->setMapObject(players[1]->getXposMap(), players[1]->getYposMap(), players[1]);






}
void Game:: handleEvents()
{
    SDL_PollEvent(&event);

    switch(event.type)
    {
    case SDL_QUIT:
        isRunning = false;
        break;
    case SDL_KEYDOWN:

        switch(event.key.keysym.sym)
        {
        case SDLK_DOWN:
//            if(map->mapp[players[0]->getYposMap()+1][players[0]->getXposMap()] == NULL)
            if(map->getObject(players[0]->getYposMap()+1, players[0]->getXposMap()) == NULL)
            {
                players[0]->setYpos(players[0]->getYpos() + (yVelocity/2));
                players[0]->Update();
                render();

                players[0]->setYpos(players[0]->getYpos() + (yVelocity/2));

//                map->mapp[players[0]->getYposMap()][players[0]->getXposMap()] = NULL;
                map->setMappToNull(players[0]->getYposMap(), players[0]->getXposMap());
                players[0]->setYposMap( players[0]->getYposMap()+1);
//                map->mapp[players[0]->getYposMap()][players[0]->getXposMap()] = players[0];
                map->setMapObject(players[0]->getYposMap(), players[0]->getXposMap(), players[0]);
                Sleep(60);
            }

//            for(int i = 0; i < 21; i ++)
//            {
//                for(int k = 0; k < 25; ++k)
//                {
//                    if(map->mapp[i][k] != NULL)
//                    {
//                        std::cout<<"*";
//                    }
//                    else
//                    {
//                        std::cout<< "0";
//                    }
//
//                }
//                std::cout<<std::endl;
//            }
//            std::cout<<std::endl;
//            Sleep(55);


            break;
        case SDLK_UP:
            if(map->getObject(players[0]->getYposMap() - 1, players[0]->getXposMap()) == NULL)
            {
                players[0]->setYpos(players[0]->getYpos() - (yVelocity/2));
                players[0]->Update();
                render();
                players[0]->setYpos(players[0]->getYpos() - (yVelocity/2));
                map->setMappToNull(players[0]->getYposMap(), players[0]->getXposMap());
                players[0]->setYposMap(players[0]->getYposMap() - 1);
                map->setMapObject(players[0]->getYposMap(), players[0]->getXposMap(), players[0]);
                Sleep(60);
            }

            break;
        case SDLK_LEFT:
            if(map->getObject(players[0]->getYposMap(), players[0]->getXposMap() - 1) == NULL)
            {
                players[0]->setXpos(players[0]->getXpos() - (xVelocity/2));
                players[0]->Update();
                render();
                players[0]->setXpos(players[0]->getXpos() - (xVelocity/2));
                map->setMappToNull(players[0]->getYposMap(), players[0]->getXposMap());
                players[0]->setXposMap(players[0]->getXposMap() - 1);
                map->setMapObject(players[0]->getYposMap(), players[0]->getXposMap(), players[0]);
                Sleep(60);
            }

            break;
        case SDLK_RIGHT:
            if(map->getObject(players[0]->getYposMap(), players[0]->getXposMap() + 1) == NULL)
            {
                players[0]->setXpos(players[0]->getXpos() + (xVelocity/2));
                players[0]->Update();
                render();
                players[0]->setXpos(players[0]->getXpos() + (xVelocity/2));
                map->setMappToNull(players[0]->getYposMap(), players[0]->getXposMap());
                players[0]->setXposMap(players[0]->getXposMap() + 1);
                map->setMapObject(players[0]->getYposMap(), players[0]->getXposMap(), players[0]);
                Sleep(60);
            }

            break;
        case SDLK_SPACE:
            players[0]->plantBomb();
            break;
        case SDLK_KP_8:
            if(map->getObject(players[1]->getYposMap() - 1, players[1]->getXposMap()) == NULL)
            {
                players[1]->setYpos(players[1]->getYpos() - (yVelocity/2));
                players[1]->Update();
                render();
                players[1]->setYpos(players[1]->getYpos() - (yVelocity/2));
                map->setMappToNull(players[1]->getYposMap(), players[1]->getXposMap());
                players[1]->setYposMap(players[1]->getYposMap() - 1);
                map->setMapObject(players[1]->getYposMap(), players[1]->getXposMap(), players[1]);
                Sleep(55);
            }
            break;
        case SDLK_KP_4:
            if(map->getObject(players[1]->getYposMap(), players[1]->getXposMap() - 1) == NULL)
            {
                players[1]->setXpos(players[1]->getXpos() - (xVelocity/2));
                players[1]->Update();
                render();
                players[1]->setXpos(players[1]->getXpos() - (xVelocity/2));
                map->setMappToNull(players[1]->getYposMap(), players[1]->getXposMap());
                players[1]->setXposMap(players[1]->getXposMap() - 1);
                map->setMapObject(players[1]->getYposMap(), players[1]->getXposMap(), players[1]);
                Sleep(55);
            }
            break;
        case SDLK_KP_6:
            if(map->getObject(players[1]->getYposMap(), players[1]->getXposMap() + 1) == NULL)
            {
                players[1]->setXpos(players[1]->getXpos() + (xVelocity/2));
                players[1]->Update();
                render();
                players[1]->setXpos(players[1]->getXpos() + (xVelocity/2));
                map->setMappToNull(players[1]->getYposMap(), players[1]->getXposMap());
                players[1]->setXposMap(players[1]->getXposMap() + 1);
                map->setMapObject(players[1]->getYposMap(), players[1]->getXposMap(), players[1]);
                Sleep(55);
            }
            break;
        case SDLK_KP_5:
            if(map->getObject(players[1]->getYposMap()+1, players[1]->getXposMap()) == NULL)
            {
                players[1]->setYpos(players[1]->getYpos() + (yVelocity/2));
                players[1]->Update();
                render();

                players[1]->setYpos(players[1]->getYpos() + (yVelocity/2));
                map->setMappToNull(players[1]->getYposMap(), players[1]->getXposMap());
                players[1]->setYposMap( players[1]->getYposMap()+1);
                map->setMapObject(players[1]->getYposMap(), players[1]->getXposMap(), players[1]);
                Sleep(55);
            }
            break;
        case SDLK_KP_ENTER:
            players[1]->plantBomb();
            Sleep(55);
            break;
        default:
            break;
        }
        break;

    default:
        break;
    }

}
void Game :: update()
{
    //visu player updatai:
    for(int i = 0; i < (int)players.size(); i++)
    {
        if(players[i]->getLives() == 0)
        {
            map->setMappToNull(players[i]->getYposMap(), players[i]->getXposMap());
            players[i]->destroyPlayerTexture();
            players.erase(players.begin() + i);
        }
        else
        players[i]->Update();
    }

}
void Game :: render()
{
    SDL_RenderClear(renderer);
    //cia dalykai kur renderinsis
    map->drawMap();
    for(int i = 0; i < (int)players.size(); i++)
    {
        if(players[i]->getLives() == 0)
        {
        }
        else
        {
            players[i]->Render();
        }

    }

    SDL_RenderPresent(renderer);

}
void Game :: clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout<<"Game cleaned"<<std::endl;
}

std::string Game::toString()
{
    std::string temp;
    temp += "Is game running: " + isRunning;
    return temp;
}

std::vector<Player*> Game::getPlayers()
{
    return players;
}
void Game::setPlayers(std::vector <Player*> pl)
{
    players = pl;
}

