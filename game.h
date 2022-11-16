#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <string>
#include <fstream>
#include <vector>
#include "object.h"
#include "map.h"
//#include <stdio.h>
class Map;
class Player;
///Game class responsible for game's updates, rendering and events
class Game
{
    public:
        Game();
        ~Game();
        ///Initiates game
        void init(const char *title, int xpos, int ypos, int width, int height, bool fullScreen);
        void handleEvents();
        void update();
        void render();
        ///Cleans the game
        void clean();
        bool running() {return isRunning;}
        static SDL_Event event;
        ///returns string of bombs information
        std::string toString();
        static SDL_Renderer *renderer;
        ///Returns vector of players
        static std::vector<Player*> getPlayers();
        ///Sets pl vector to game's players vector
        static void setPlayers(std::vector <Player*> pl);


    private:
        static std::vector <Player*> players;
        static Map *map;
        bool isRunning;
        SDL_Window *window;
};


#endif // GAME_H_INCLUDED
