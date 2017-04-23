#ifndef __HARLEY_H_
#define __HARLEY_H_

#include "sfml.h"

#include "player.h"
#include "situation.h"

namespace Harley
{
    class Harley
    {
        sf::RenderWindow window;
        Situation *battle;
        Situation *overworld;
        Player *currentPlayer;
        Situation *currentSituation;

        void handleButtonPress(sf::Event::JoystickButtonEvent);
        void handleButtonRelease(sf::Event::JoystickButtonEvent);
        void handleAxisMotion(sf::Event::JoystickMoveEvent);
        void handleKeyDown(sf::Event::KeyEvent);
        void handleKeyUp(sf::Event::KeyEvent);

      public:
        Harley ();

        void mainloop();
        void quit();
    };
}

#endif // __HARLEY_H_
