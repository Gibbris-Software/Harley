#ifndef __PLAYER_H_
#define __PLAYER_H_

#include "sfml.h"
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

        int animation_state;

        sf::IntRect front [2];
        sf::IntRect back [2];
        sf::IntRect left [2];
        sf::IntRect right [2];
        sf::Texture texture;
        sf::Sprite sprite;

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
        int getSpeed();
        int getDiagonalSpeed();
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

        void nextAnimation();
        sf::Sprite direction(int, int);
    };
}

#endif // __PLAYER_H_
