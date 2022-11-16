#include <SDL.h>
#include <iostream>
#include <string>
#include "game.h"
#include "player.h"
#include <fstream>
#include <assert.h>
#include <windows.h>
#include "map.h"
#include <exception>
#include <sstream>
#include "TextureManager.h"

using namespace std;
Game *game = nullptr;
//void playerTests()
//{
//    Player *testPlayr;
//    int x = 20;
//    int y = 10;
//    Map *map = new Map;
//    testPlayr = new Player("images/stickman.png", x, y, map);
//    vector<Player*> testPlayers;
//
//    clog<<"Testing constructor with getXpos"<<endl;
//    assert(testPlayr->getXpos() == x);
//    clog<<"Test passed"<<endl<<endl;
//
//    clog<<"Testing setXpos"<<endl;
//    testPlayr->setXpos(y);
//    assert(testPlayr->getYpos() == y);
//    clog<<"Test passed"<<endl<<endl;
//
//    clog<<"Testing increaseMaxBombs"<<endl;
//    testPlayr->setMaxBombs(1);
//    testPlayr->increaseMaxBombs();
//    assert(testPlayr->getMaxBombs() == 2);
//    clog<<"Test passed"<<endl<<endl;
//
//    clog<<"Testing bomb planting"<<endl;
//    testPlayr->setXpos(500);
//    testPlayr->plantBomb();
//    assert(testPlayr->getActiveBombs() == 1);
//    clog<<"Test passed"<<endl<<endl;
//
//    clog<<"Testing operator +="<<endl;
//    testPlayr->setMaxBombs(1);
//    testPlayr->operator += (2);
//    assert(testPlayr->getMaxBombs() == 3);
//    clog<<"Test passed"<<endl<<endl;
//    delete map;
//    delete testPlayr;
//
//}
//void bombTests()
//{
//    Player *testPlrBomb;
//    Map *map = new Map;
//    testPlrBomb = new Player("images/stickman.png", 20, 10, map);
//    clog<<"Testing  bomb planting position"<<endl;
//    Bomb bomb(testPlrBomb, map);
//    testPlrBomb->plantBomb();
//    assert(bomb.getXpos() == testPlrBomb->getXpos());
//    clog<<"Test passed"<<endl<<endl;
//    delete testPlrBomb;
//    delete map;
//
//}
//void mapTests()
//{
//    clog<<"Testing if map created successfully"<<endl;
//    Player *testPlayr;
//    Map *map = new Map();
//    testPlayr = new Player("images/stickman.png", 0, 0, map);
//    map->setMapName("testing");
//    assert(map->getMapName() == "testing");
//    clog<<"Test passed"<<endl<<endl;
//    delete testPlayr;
//    delete map;
//}
//void streamTests()
//{
//    clog<<"Testing <<"<<endl;
//    Player *testPlayr;
//    Map *map = new Map();
//    testPlayr = new Player("images/stickman.png", 0, 0, map);
//    string str1 = testPlayr->toString();
//    string str2;
//    stringstream ss;
//    ss<<*testPlayr;
//    getline(ss, str2);
//    assert(str1.compare(str2) == 0);
//    delete testPlayr;
//    delete map;
//    clog<<"Test passed"<<endl<<endl;
//
//}
//void textureTests()
//{
//    clog<<"Testing TextureManager"<<endl;
//    assert(TextureManager::loadTexture("images/stickman.png") != 0);
//    clog<<"Test passed"<<endl;
//}
//void test()
//{
//    clog<<"Tests started"<<endl<<endl;
//    playerTests();
//    bombTests();
//    mapTests();
//    textureTests();
//    clog<<"Tests ended"<<endl;
//
//}


int main( int argc, char* argv[] )
{
    const int FPS  = 60;
    const int frameDelay = 1000 / FPS;
    Uint32 frameStart;
    int frameTime;

    std::ofstream file("file.txt");
    std::clog.rdbuf(file.rdbuf());
    game = new Game();
    game->init("Bomberman", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 707, false);
    file.close();
    try
    {
        while(game->running())
        {
            frameStart = SDL_GetTicks();
            game->handleEvents();
            game->update();
            game->render();

            frameTime = SDL_GetTicks() - frameStart;
            if(frameDelay > frameTime)
            {
                SDL_Delay(frameDelay - frameTime);
            }
        }
    }
    catch(std::exception const &e)
    {
        cerr<<e.what()<<std::endl;
    }
    catch(char const* msg)
    {
        cerr<<msg<<endl;
    }
    catch(...)
    {
        cerr<<"Unknown type of exception"<<endl;
    }

    game->clean();
	return 0;
}
