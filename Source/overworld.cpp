#include <SDL2/SDL.h>
#include "overworld.h"

namespace Harley
{
	Overworld::Overworld (Player* player, SDL_Renderer* renderer)
    {
        tiles = new Tileset ("Resources/anais.png", renderer);
        map = new Map ("Resources/anais.map");
        character = player;
        movingRight = false;
        movingUp = false;
        movingLeft = false;
        movingDown = false;
        speed = 3;
    }

    void Overworld::redraw(SDL_Renderer* renderer)
    {
        SDL_RenderClear(renderer);
        for (int i = 0; i < 20; i++) {
        	for (int j = 0; j < 15; j++) {
        		int tile = map->tileAt(i, j);
                tiles->renderTile(tile, i, j, renderer);
        	}
        }
    }
    
    void Overworld::startUp(){
        movingUp = true;
        movingDown = false;
        if (movingLeft || movingRight) {
            speed = 2;
        }
    }

    void Overworld::startDown(){
        movingDown = true;
        movingUp = false;
        if (movingLeft || movingRight) {
            speed = 2;
        }
    }

    void Overworld::startLeft(){
        movingLeft = true;
        movingRight = false;
        if (movingUp || movingDown) {
            speed = 2;
        }
    }

    void Overworld::startRight ()
    {
        movingRight = true;
        movingLeft = false;
        if (movingUp || movingDown) {
            speed = 2;
        }
    }

    void Overworld::stopUp(){
        movingUp = false;
        speed = 3;
    }

    void Overworld::stopDown(){
        movingDown = false;
        speed = 3;
    }

    void Overworld::stopLeft(){
        movingLeft = false;
        speed = 3;
    }

    void Overworld::stopRight ()
    {
        movingRight = false;
        speed = 3;
    }

    void Overworld::update(Uint32 time){
        if (movingUp) {
            character->moveUpTile (speed);
        } else if (movingDown) {
            character->moveDownTile (speed);
        }

        if (movingRight) {
            character->moveRightTile (speed);
        } else if (movingLeft) {
            character->moveLeftTile (speed);
        }
    }
}

