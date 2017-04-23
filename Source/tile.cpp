#include "tile.h"
#include "constants.h"
#include "sfml.h"
#include <iostream>

namespace Harley
{
	Tileset::Tileset (std::string location)
    {
        sheet.loadFromFile(location);
        sheet.setSmooth(false);
        width = sheet.getSize().x / TILE_SIZE;
        height = sheet.getSize().y / TILE_SIZE;
        sprite.setTexture(sheet);
        sprite.setScale(SCALE, SCALE);
    }

    void Tileset::renderTile(int which, int x, int y, sf::RenderWindow& window){
        int tx = which % width;
        int ty = which / height;
        sprite.setTextureRect(sf::IntRect(tx*TILE_SIZE, ty*TILE_SIZE, TILE_SIZE, TILE_SIZE));
        sprite.setPosition(x*SCALE, y*SCALE);

        window.draw(sprite);
    }
}

