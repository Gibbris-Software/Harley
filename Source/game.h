#ifndef __HARLEY_H_
#define __HARLEY_H_

#include "sfml.h"

#include "player.h"
#include "overworld.h"
#include "battle.h"
#include "house.h"
#include "city.h"

namespace Harley
{
    enum Situation {
        OVERWORLD,
        BATTLE,
        HOUSE,
        CITY
    };

    class Game
    {
        sf::RenderWindow window;
        Battle battle;
        Overworld overworld;
        House house;
        City city;
        Player player;
        Situation mode;
        Situation lastMode;

        void handleButtonPress(sf::Event::JoystickButtonEvent);
        void handleButtonRelease(sf::Event::JoystickButtonEvent);
        void handleAxisMotion(sf::Event::JoystickMoveEvent);
        void handleKeyDown(sf::Event::KeyEvent);
        void handleKeyUp(sf::Event::KeyEvent);

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
