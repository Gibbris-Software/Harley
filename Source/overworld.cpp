#include <iostream>
#include "sfml.h"
#include "overworld.h"
#include "constants.h"

namespace Harley
{
    Overworld::Overworld (Player* player)
    {
        tiles = new Tileset ("Resources/anais.png");
        map = new Map ("Resources/beauve", 1440, 960, 3, 3);
        character = player;
        movingRight = false;
        movingUp = false;
        movingLeft = false;
        movingDown = false;
        speed = BASE_SPEED;
    }

    void Overworld::redraw(sf::RenderWindow& window)
    {
        int startX = std::max(0, (character->getTileX()/TILE_SIZE)-(TILE_WIDTH+1)/2);
        int startY = std::max(0, (character->getTileY()/TILE_SIZE)-(TILE_HEIGHT+1)/2);
        int endX = std::min(map->width(), startX+TILE_WIDTH);
        int endY = std::min(map->height()-1, startY+TILE_HEIGHT);
        startX = endX - TILE_WIDTH;
        startY = endY - TILE_HEIGHT;
        int centerX = std::max(std::min(character->getTileX(), map->width()*TILE_SIZE-SCREEN_WIDTH/2), SCREEN_WIDTH/2);
        int centerY = std::max(std::min(character->getTileY(), map->height()*TILE_SIZE-SCREEN_HEIGHT/2), SCREEN_HEIGHT/2);
        // std::cout << endX << ", " << endY << ", " << character->getTileX() / TILE_SIZE << ", " << character->getTileY() / TILE_SIZE << std::endl;
        for (int i = startX; i <= endX; i++) {
        	for (int j = startY; j <= endY; j++) {
        		int tile = map->tileAt(i, j);
                tiles->renderTile(tile, (TILE_SIZE*i)-centerX + SCREEN_WIDTH/2, (TILE_SIZE*j)-centerY+SCREEN_HEIGHT/2, window);
        	}
        }
        // character->next_animation();
        sf::Sprite sprite = character->direction(movingRight-movingLeft, movingDown-movingUp);
        sprite.setPosition((character->getTileX()-centerX+SCREEN_WIDTH/2)*SCALE, (character->getTileY()-centerY+SCREEN_HEIGHT/2)*SCALE);
        window.draw(sprite);
    }

    void Overworld::startUp(){
        movingUp = true;
        movingDown = false;
        if (movingLeft || movingRight) {
            speed = DIAGONAL_SPEED;
        }
    }

    void Overworld::startDown(){
        movingDown = true;
        movingUp = false;
        if (movingLeft || movingRight) {
            speed = DIAGONAL_SPEED;
        }
    }

    void Overworld::startLeft(){
        movingLeft = true;
        movingRight = false;
        if (movingUp || movingDown) {
            speed = DIAGONAL_SPEED;
        }
    }

    void Overworld::startRight ()
    {
        movingRight = true;
        movingLeft = false;
        if (movingUp || movingDown) {
            speed = DIAGONAL_SPEED;
        }
    }

    void Overworld::stopUp(){
        movingUp = false;
        speed = BASE_SPEED;
    }

    void Overworld::stopDown(){
        movingDown = false;
        speed = BASE_SPEED;
    }

    void Overworld::stopLeft(){
        movingLeft = false;
        speed = BASE_SPEED;
    }

    void Overworld::stopRight ()
    {
        movingRight = false;
        speed = BASE_SPEED;
    }

    void Overworld::update(){
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

