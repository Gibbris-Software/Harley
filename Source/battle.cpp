#include <SDL2/SDL.h>

#include "battle.h"

namespace Harley
{
    Battle::Battle (Player *player, std::string where, SDL_Renderer* renderer)
    {
        tiles = new Tileset ("Resources/anais.png", renderer);
        map = new Map ("Resources/anais.map");
        character = player;
        movingRight = false;
        movingUp = false;
        movingLeft = false;
        movingDown = false;
    }

    void Battle::redraw(SDL_Renderer* renderer)
    {
        SDL_RenderClear(renderer);
        for (int i = 0; i < 20; i++) {
        	for (int j = 0; j < 15; j++) {
        		int tile = map->tileAt(i, j);
                tiles->renderTile(tile, i, j, renderer);
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

    void Battle::update(Uint32 time){
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

