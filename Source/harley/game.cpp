#include <iostream>

#include "sfml.h"

#include "constants.h"
#include "game.h"


namespace Harley
{
    Game::Game() {
        game.create(SCALE*SCREEN_WIDTH, SCALE*SCREEN_HEIGHT, "Harley");
        littleoak.setup(game, player);
        anais.openFromFile("Resources/anais.wav");
        anais.setLoop(true);
        anais.play();
    }

    void Game::mainloop(){
        game.run();
    }

//    void Game::handleKeyDown(sf::Event::KeyEvent event){
//        if (mode == OVERWORLD){
//            overworld.handleKeyDown(event);
//        } else if (mode == BATTLE){
//            battle.handleKeyDown(event);
//        } else if (mode == HOUSE){
//            house.handleKeyDown(event);
//        } else if (mode == CITY){
//            city.handleKeyDown(event);
//        }
//    }
//
//    void Game::handleKeyUp(sf::Event::KeyEvent event){
//        if (mode == OVERWORLD){
//            overworld.handleKeyUp(event);
//        } else if (mode == BATTLE){
//            battle.handleKeyUp(event);
//        } else if (mode == HOUSE){
//            house.handleKeyUp(event);
//        } else if (mode == CITY){
//            city.handleKeyUp(event);
//        }
//    }
//
//    void Game::handleButtonPress(sf::Event::JoystickButtonEvent event){
//        switch(event.button){
//            default:
//                break;
//        }
//    }
//
//    void Game::handleButtonRelease(sf::Event::JoystickButtonEvent event){
//        switch(event.button){
//            default:
//                break;
//        }
//    }
//
//    void Game::handleAxisMotion(sf::Event::JoystickMoveEvent event){
//        /*switch(event.axis){
//            case sf::Joystick::PovY:
//                if (event.position < 0){
//                    currentSituation->startUp();
//                } else if (event.position > 0) {
//                    currentSituation->startDown();
//                } else {
//                    currentSituation->stopUp();
//                    currentSituation->stopDown();
//                }
//                break;
//            case sf::Joystick::PovX:
//                if (event.position < 0){
//                    currentSituation->startLeft();
//                } else if (event.position > 0) {
//                    currentSituation->startRight();
//                } else {
//                    currentSituation->stopLeft();
//                    currentSituation->stopRight();
//                }
//                break;
//            default:
//                break;
//        }*/
//    }

    void Game::quit(){
        window.close();
        // delete battle;
    }
}
