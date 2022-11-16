#ifndef GAMEOBJECT_H_INCLUDED
#define GAMEOBJECT_H_INCLUDED
#include "game.h"
#include "bomb.h"
#include <string>
#include <iostream>
#include <vector>
#include "movableObject.h"
#include "map.h"
#include "object.h"
#define startMaxBombs 1
#define startXpos1 22
#define startYpos1 22
#define startExplodeDistance 1
class Bomb;
///Class responsible for player's actions
class Player : public MovableObject
{
    public:
        Player(const char *textureSheet, const int x, const int y, Map *map);
        Player(const char *textureSheet, const int x, const int y);
        virtual ~Player();
        void Update();
        void Render();
        void plantBomb();
        ///Decreases activeBombs field by one
        void minusActiveBombs();
        int getXpos() const;
        int getYpos() const;
        void setXpos(int x);
        void setYpos(int y);
        void setMaxBombs(int x);
        int getMaxBombs() const;
        int getActiveBombs() const;
        void destroyPlayerTexture()const;
        ///Returns string of player's information
        std::string toString() const;
        void setName(std::string n);
        std::string getName()const;
        ///Operator expanding players max bombs by 1
        Player& operator ++();
        ///Operator expanding players max bombs by i value
        Player& operator +=(int i);
        ///Operator printing information about player
        friend std::ostream& operator<<(std::ostream& os, const Player &c);
        ///Operator writing information about player
        friend std::istream& operator>>(std::istream& is, Player &c);
        ///Increases maxBombs by 1
        void increaseMaxBombs();
        ///Sets isAlive to false
        void setToDead();
        ///Returns isAlive
        bool getIsAlive() const;
        ///Sets isAlive to true
        void setToAlive();
        bool isDestroyable(){return true;}
        void setXposMap(int x);
        int getXposMap() const;
        void setYposMap(int y);
        int getYposMap()const;
        SDL_Texture *getTexture();
        void destroyMapObject(int x, int y);
        void setBombExplodeDistance(int x);
        int getBombExplodeDistance() const;
        int getLives() const;
        void setLives(int x);
        void decreaseLives();

    private:
        static std::vector <Player*> players;
        ///Vector holding bombs
        std::vector <Bomb*> bombs;
        ///Player's name
        std::string name;
        SDL_Texture *playerTexture;
        ///Field showing if player has planted any bombs
        SDL_Texture *hpTexture;
        SDL_Texture *bombCount;
        int startXpos;
        SDL_Rect srcHp, srcBombs, destHp, destBombs;
        bool areActiveBombs();
        ///Player's x position
        int xpos;
        ///Player's y position
        int ypos;
        ///How many bombs can player plant
        int maxBombs;
        ///How many bombs are active
        int activeBombs;
        SDL_Rect srcRect, destRect;
        bool isAlive;
        int xposMap;
        int yposMap;
        Map *map;
        int bombExplodeDistance;
        int lives;
};


#endif // GAMEOBJECT_H_INCLUDED
