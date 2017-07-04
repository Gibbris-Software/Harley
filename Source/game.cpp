#include <iostream>

#include "sfml.h"

#include "constants.h"
#include "game.h"


namespace Harley
{
    Game::Game(): mode(OVERWORLD) {
        window.create(sf::VideoMode(SCALE*SCREEN_WIDTH, SCALE*SCREEN_HEIGHT), "Harley");
        window.setFramerateLimit(30);
        anais.openFromFile("Resources/anais.wav");
        anais.setLoop(true);
        anais.play();
    }

    void Game::mainloop(){
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
                        break;
                        /*     4                     5
                        //   .-------.       .---------.
                        //  /         \_____/      3    \
                        //  |  9      6  8  7    2    1 |
                        //  |                      0    |
                        //                    10
                        //*/
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
                player.nextAnimation();
                prevTime = elapsedTime;
            }
            if (mode == OVERWORLD){
                overworld.update(player, *this);
                overworld.redraw(window, player);
            } else if (mode == BATTLE){
                battle.update(player, *this);
                battle.redraw(window, player);
            } else if (mode == HOUSE){
                house.update(player, *this);
                house.redraw(window, player);
            } else if (mode == CITY){
                city.update(player, *this);
                city.redraw(window, player);
            }
            window.display();
        }
    }

    void Game::handleKeyDown(sf::Event::KeyEvent event){
        if (mode == OVERWORLD){
            overworld.handleKeyDown(event);
        } else if (mode == BATTLE){
            battle.handleKeyDown(event);
        } else if (mode == HOUSE){
            house.handleKeyDown(event);
        } else if (mode == CITY){
            city.handleKeyDown(event);
        }
    }

    void Game::handleKeyUp(sf::Event::KeyEvent event){
        if (mode == OVERWORLD){
            overworld.handleKeyUp(event);
        } else if (mode == BATTLE){
            battle.handleKeyUp(event);
        } else if (mode == HOUSE){
            house.handleKeyUp(event);
        } else if (mode == CITY){
            city.handleKeyUp(event);
        }
    }

    void Game::handleButtonPress(sf::Event::JoystickButtonEvent event){
        switch(event.button){
            default:
                break;
        }
    }

    void Game::handleButtonRelease(sf::Event::JoystickButtonEvent event){
        switch(event.button){
            default:
                break;
        }
    }

    void Game::handleAxisMotion(sf::Event::JoystickMoveEvent event){
        /*switch(event.axis){
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
        }*/
    }

    void Game::quit(){
        window.close();
        // delete battle;
    }
}
