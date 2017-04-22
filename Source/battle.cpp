#include "sfml.h"

#include "battle.h"
#include "constants.h"

namespace Harley
{
    Battle::Battle (Player *player, std::string where)
    {
        tiles = new Tileset ("Resources/anais.png");
        map = new Map ("Resources/anais.map");
        character = player;
        movingRight = false;
        movingUp = false;
        movingLeft = false;
        movingDown = false;
    }

    void Battle::redraw(sf::RenderWindow &window)
    {
        //SDL_RenderClear(renderer);
        for (int i = 0; i < 20; i++) {
        	for (int j = 0; j < 15; j++) {
        		int tile = map->tileAt(i, j);
                tiles->renderTile(tile, i*TILE_SIZE, j*TILE_SIZE, window);
        	}
        }

    }

    void Battle::startUp(){
        movingUp = true;
        movingDown = false;
        if (movingLeft || movingRight) {
            speed = 2;
        }
    }

    void Battle::startDown(){
        movingDown = true;
        movingUp = false;
        if (movingLeft || movingRight) {
            speed = 2;
        }
    }

    void Battle::startLeft(){
        movingLeft = true;
        movingRight = false;
        if (movingUp || movingDown) {
            speed = 2;
        }
    }

    void Battle::startRight ()
    {
        movingRight = true;
        movingLeft = false;
        if (movingUp || movingDown) {
            speed = 2;
        }
    }

    void Battle::stopUp(){
        movingUp = false;
        speed = 3;
    }

    void Battle::stopDown(){
        movingDown = false;
        speed = 3;
    }

    void Battle::stopLeft(){
        movingLeft = false;
        speed = 3;
    }

    void Battle::stopRight ()
    {
        movingRight = false;
        speed = 3;
    }

    void Battle::update(){
        if (movingUp) {
            character->moveUpBattle (speed);
        } else if (movingDown) {
            character->moveDownBattle (speed);
        }

        if (movingRight) {
            character->moveRightBattle (speed);
        } else if (movingLeft) {
            character->moveLeftBattle (speed);
        }
    }
}

