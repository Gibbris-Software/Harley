#include "enemy.h"


namespace Harley {
    Enemy::Enemy()
    {
        //ctor
    }

    Enemy::~Enemy()
    {
        //dtor
    }

    std::vector<Attack> Enemy::getAttacks(){
        return attacks;
    }
}
