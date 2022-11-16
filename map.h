#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED
#include "game.h"
#include <string>
#include "object.h"
#define powerUpLimit 10
///Game's map
class Map
{
    private:
        SDL_Rect src, dest;
        SDL_Texture *path;
        std::string mapName;
        Object *mapp[21][25];

    public:
        void setMappX(int& x);
        void setMappY(int& y);
        Map();
        ~Map();
        ///Fills map from two dimensional array
        void loadMap(int arr[21][25]);
        ///draws map's textures
        void drawMap();
        ///returns map name
        std::string getMapName();
        void setMapName(std::string& n);
        void setMappToNull(int x, int y);
        void setMapObject(int x, int y, Object *obj);
        Object* getObject(int x, int y);
        void randomGenerator(int arr[21][25]);
};


#endif // MAP_H_INCLUDED
