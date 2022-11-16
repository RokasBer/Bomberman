#ifndef BOMB_H_INCLUDED
#define BOMB_H_INCLUDED
#include <time.h>
#include <string>
#include <string.h>
#include "game.h"
#include "player.h"

class Player;

///Bomb's class responsible for bombs explosions, rendering, updating
class Bomb
{
    public:
        ///Constructor containing pointer of bomb's owner
        Bomb(Player *owner, Map *mapp);
        ~Bomb();
        ///Renders bomb and it's explosion
        void renderBomb();
        ///Sets bomb's position
        void setPos(int &x, int &y);
        ///Returns SDL_Rect of bomb's position
        int getXpos() const;
        ///Returns bomb's Y position
        int getYpos()const;
        ///Sets current time for start
        void setStart();
        ///Sets t value to start
        void setStart(double &t);
        ///Returns start time of planted bomb
        clock_t getStart()const;
        ///Sets current time for end
        void setEnd();
        ///Returns end time of planted bomb
        clock_t getEnd()const;
        ///Explodes bomb
        void explosion();
        ///Sets bombTimer to t value
        void setBombTimer(double &t);
        ///returns bombTimer
        double getBombTimer() const;
        ///Returns string of bomb's information
        std::string toString() const;
        ///Returns bool if bomb is active
        bool getIsActive() const;
        ///Sets bool field isActive to true
        void setActive();
        void explode();
        void setmapp(int &x, int &y);
        int getXMapp() const;
        int getYMapp() const;


    private:
        Bomb(const Bomb& obj):owner(obj.owner), map(obj.map){}
        Bomb& operator=(const Bomb& temp)
        {
            owner = temp.owner;
            map = temp.map;
            return *this;
        }
        ///Bomb's owner
        Player *owner;
        ///Bomb texture
        SDL_Texture *bombTexture;
        ///Explosion texture
        SDL_Texture *explosionTexture;
        ///Source of bomb
        SDL_Rect srcBomb;
        ///Destination of bomb
        SDL_Rect destBomb;
        ///Source of explosion
        SDL_Rect srcExplosion;
        ///Destination of bomb
        SDL_Rect destExplosion;
        ///Time when bomb was planted
        clock_t start;
        ///Time when bomb will explode
        clock_t end;
        ///Time between bomb's plant and it's explosion
        double bombTimer;
        ///Bool if bomb is active
        bool isActive;
        int xMapp;
        int yMapp;
        Map *map;
};


#endif // BOMB_H_INCLUDED
