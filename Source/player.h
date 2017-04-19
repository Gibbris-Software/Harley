#ifndef __PLAYER_H_
#define __PLAYER_H_

#include "ability.h"
#include "attack.h"

namespace Harley {
    class Player {
        int hp;
        int stamina;
        int attack_strength;
        int defence;
        int weight;
        int max_weight_load;
        
        int tile_x;
        int tile_y;
        int battle_x;
        int battle_y;

        Ability ability;
        SpecialAttack special_attack;
        
      public:
        Player();
        void attack();
        void strike();
        void special();
        void block();
        void dealDamage(int);
        void startBattle();
        
        int getHealth();
        int getStamina();
        int getBattleX();
        int getBattleY();
        int getTileX();
        int getTileY();
        
        void moveUpBattle(int);
        void moveDownBattle(int);
        void moveLeftBattle(int);
        void moveRightBattle(int);
        void moveUpTile(int);
        void moveDownTile(int);
        void moveLeftTile(int);
        void moveRightTile(int);
    };
}

#endif // __PLAYER_H_
