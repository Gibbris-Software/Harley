#ifndef HARLEY_H
#define HARLEY_H

#include "sfml.h"

#include "possum/possum.h"

#include "player.h"
#include "overworld.h"
#include "battle.h"
#include "house.h"
#include "city.h"

namespace Harley
{
    class Game
    {
        sf::RenderWindow window;
        Overworld overworld;
        Player player;
        possum::Game game;

        sf::Music anais;

      public:
        Game ();

        void startBattle(std::string);
        void leaveBattle();
        void enterHouse(std::string);
        void leaveHouse();
        void enterCity(std::string, int, int);
        void leaveCity(std::string, int, int);
        void save();

        void mainloop();
        void quit();
    };
}

#endif // __HARLEY_H_
