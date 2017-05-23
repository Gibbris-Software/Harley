#ifndef __ENEMY_H_
#define __ENEMY_H_

#include "vector"
#include "player.h"
#include "map.h"
#include "attack.h"

namespace Harley {
    class Enemy {
        int x;
        int y;
        int health;
        std::vector<Attack> attacks;
      public:
        Enemy(int _x, int _y, int h): x(_x), y(_y), health(h);
        virtual int getX();
        virtual int getY();
        virtual void update(Map, Player*) = 0;
        virtual int getHealth();
    }
}

#endif // __ENEMY_H_
