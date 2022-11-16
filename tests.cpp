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
#include "wall.h"

using namespace std;
Game *game = nullptr;
void playerTests()
{
    Map *map = new Map;
    Player *testPlayr;
    int x = 20;
    int y = 10;
    testPlayr = new Player("images/stickman.png", x, y, map);
    vector<Player*> testPlayers;

    clog<<"Testing constructor with getXpos"<<endl;
    assert(testPlayr->getXpos() == x);
    clog<<"Test passed"<<endl<<endl;

    clog<<"Testing setXpos"<<endl;
    testPlayr->setXpos(y);
    assert(testPlayr->getYpos() == y);
    clog<<"Test passed"<<endl<<endl;

    clog<<"Testing increaseMaxBombs"<<endl;
    testPlayr->setMaxBombs(1);
    testPlayr->increaseMaxBombs();
    assert(testPlayr->getMaxBombs() == 2);
    clog<<"Test passed"<<endl<<endl;

    clog<<"Testing bomb planting"<<endl;
    testPlayr->setXpos(500);
    testPlayr->plantBomb();
    assert(testPlayr->getActiveBombs() == 1);
    clog<<"Test passed"<<endl<<endl;

    clog<<"Testing operator +="<<endl;
    testPlayr->setMaxBombs(1);
    testPlayr->operator += (2);
    assert(testPlayr->getMaxBombs() == 3);
    delete map;
    delete testPlayr;
    clog<<"Test passed"<<endl<<endl;

}
void bombTests()
{
    Player *testPlrBomb;
    Map *map = new Map;
    testPlrBomb = new Player("images/stickman.png", 22, 22, map);
    clog<<"Testing  bomb planting position"<<endl;
    Bomb bomb(testPlrBomb, map);
    testPlrBomb->plantBomb();
    assert(bomb.getXMapp() == testPlrBomb->getXposMap());
    delete testPlrBomb;
    delete map;
    clog<<"Test passed"<<endl<<endl;

}
void mapTests()
{
    clog<<"Testing if map created successfully"<<endl;
    Map *map = new Map;
    map->setMapName("testing");
    assert(map->getMapName() == "testing");
    clog<<"Test passed"<<endl<<endl;
    delete map;
}
void objectTests()
{
    clog<<"Testing wall"<<endl;
    Wall wall;
    assert(wall.isDestroyable() == 0);
    clog<<"Test passed"<<endl<<endl;
}
void streamTests()
{
    clog<<"Testing <<"<<endl;
    Player *testPlayr;
    testPlayr = new Player("images/stickman.png", 0, 0);
    string str1 = testPlayr->toString();
    string str2;
    stringstream ss;
    ss<<*testPlayr;
    getline(ss, str2);
    assert(str1.compare(str2) == 0);
    delete testPlayr;
    clog<<"Test passed"<<endl<<endl;
}
void textureTests()
{
    clog<<"Testing TextureManager"<<endl;
    Game *game = new Game;
    SDL_Window *window = SDL_CreateWindow("test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 675, false);
    game->renderer = SDL_CreateRenderer(window, -1, 0);
    assert(TextureManager::loadTexture("images/player.png") != 0);
    delete game;
    clog<<"Test passed"<<endl<<endl;
}
void test()
{
    clog<<"Tests started"<<endl<<endl;
    playerTests();
    bombTests();
    mapTests();
    streamTests();
    textureTests();
    objectTests();
    clog<<"Tests ended"<<endl;
}


int main( int argc, char* argv[] )
{
    test();
	return 0;
}
