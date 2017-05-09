#include <iostream>

#include "sfml.h"

#include "constants.h"
#include "harley.h"
#include "situation.h"
#include "player.h"
#include "battle.h"
#include "overworld.h"


namespace Harley
{
    Harley::Harley(){
        window.create(sf::VideoMode(SCALE*SCREEN_WIDTH, SCALE*SCREEN_HEIGHT), "Harley");
        window.setFramerateLimit(30);

        currentPlayer = new Player ();

        // battle = new Battle (&(*currentPlayer), "anais", &(*renderer));
        overworld = new Overworld (&(*currentPlayer));
        currentSituation = new Battle(&(*currentPlayer), "anais");
    }

    void Harley::mainloop(){
        sf::Event e;
        bool running = true;
        sf::Clock clock;
        sf::Time prevTime = clock.getElapsedTime();
        sf::Time elapsedTime;
        while (running){
            elapsedTime = clock.getElapsedTime();
            while (window.pollEvent(e)){
                switch (e.type){
                    case sf::Event::Closed:
                        running = false;
                        break;
                    case sf::Event::KeyPressed:
                        handleKeyDown(e.key);
                        break;
                    case sf::Event::KeyReleased:
                        handleKeyUp(e.key);
                        break;
                    case sf::Event::JoystickConnected:
                        std::cout << sf::Joystick::getButtonCount(0) << std::endl;
                        break;
                    case sf::Event::JoystickButtonPressed:
                        //std::cout << e.joystickButton.button << std::endl;
                        handleButtonPress(e.joystickButton);
                        //     4                     5
                        //   .-------.       .---------.
                        //  /         \_____/      3    \
                        //  |  9      6  8  7    2    1 |
                        //  |                      0    |
                        //                    10
                    case sf::Event::JoystickButtonReleased:
                        handleButtonRelease(e.joystickButton);
                    case sf::Event::JoystickMoved:
                        handleAxisMotion(e.joystickMove);
                        break;
                    default:
                        break;
                }
            }
            if (elapsedTime.asMilliseconds() - 100 > prevTime.asMilliseconds()){
                currentPlayer->nextAnimation();
                prevTime = elapsedTime;
            }
            currentSituation->update();
            currentSituation->redraw(window);
            window.display();
        }
    }

    void Harley::handleKeyDown(sf::Event::KeyEvent event){
        switch(event.code){
            case sf::Keyboard::W:
                currentSituation->startUp();
                break;
            case sf::Keyboard::S:
                currentSituation->startDown();
                break;
            case sf::Keyboard::A:
                currentSituation->startLeft();
                break;
            case sf::Keyboard::D:
                currentSituation->startRight();
                break;
            default:
                std::cout << event.code << std::endl;
        }
    }

    void Harley::handleKeyUp(sf::Event::KeyEvent event){
        switch(event.code){
            case sf::Keyboard::W:
                currentSituation->stopUp();
                break;
            case sf::Keyboard::S:
                currentSituation->stopDown();
                break;
            case sf::Keyboard::A:
                currentSituation->stopLeft();
                break;
            case sf::Keyboard::D:
                currentSituation->stopRight();
                break;
            default:
                break;
        }
    }

    void Harley::handleButtonPress(sf::Event::JoystickButtonEvent event){
        switch(event.button){
            default:
                break;
        }
    }

    void Harley::handleButtonRelease(sf::Event::JoystickButtonEvent event){
        switch(event.button){
            default:
                break;
        }
    }

    void Harley::handleAxisMotion(sf::Event::JoystickMoveEvent event){
        switch(event.axis){
            case sf::Joystick::PovY:
                if (event.position < 0){
                    currentSituation->startUp();
                } else if (event.position > 0) {
                    currentSituation->startDown();
                } else {
                    currentSituation->stopUp();
                    currentSituation->stopDown();
                }
                break;
            case sf::Joystick::PovX:
                if (event.position < 0){
                    currentSituation->startLeft();
                } else if (event.position > 0) {
                    currentSituation->startRight();
                } else {
                    currentSituation->stopLeft();
                    currentSituation->stopRight();
                }
                break;
            default:
                break;
        }
    }

    void Harley::quit(){
        delete overworld;
        delete currentPlayer;
        window.close();
        // delete battle;
    }
}
