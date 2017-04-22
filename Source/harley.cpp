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
        window.create(sf::VideoMode(2*SCREEN_WIDTH, 2*SCREEN_HEIGHT), "Harley");
        window.setVerticalSyncEnabled(true);

        currentPlayer = new Player ();

        // battle = new Battle (&(*currentPlayer), "anais", &(*renderer));
        overworld = new Overworld (&(*currentPlayer));
        currentSituation = overworld;
    }

    void Harley::mainloop(){
        sf::Event e;
        bool running = true;
        while (running){
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
                    default:
                        break;
                }
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
                break;
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

    void Harley::quit(){
        delete overworld;
        delete currentPlayer;
        window.close();
        // delete battle;
    }
}
