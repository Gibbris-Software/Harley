#include <iostream>
#include "sdl_include.h"
#include "overworld.h"
#include "constants.h"

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
        for (int i = (character->getTileX()/TILE_SIZE)-(TILE_WIDTH+1)/2; i <= (character->getTileX()/TILE_SIZE)+(TILE_WIDTH+1)/2; i++) {
        	for (int j = (character->getTileY()/TILE_SIZE)-(TILE_HEIGHT+1)/2; j <= (character->getTileY()/TILE_SIZE)+(TILE_HEIGHT+1)/2; j++) {
        		int tile = map->tileAt(i, j);
                tiles->renderTile(tile, (TILE_SIZE*i)-character->getTileX()+SCREEN_WIDTH/2, (TILE_SIZE*j)-character->getTileY()+SCREEN_HEIGHT/2, renderer);
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

