#ifndef __TILE_H_
#define __TILE_H_

#include <string>
#include "sfml.h"

namespace Harley {
    class Tileset {
        sf::Texture sheet;
        sf::Sprite sprite;
        int width;
        int height;
      public:
        Tileset(std::string);
        void renderTile(int, int, int, sf::RenderWindow&);
    };
}

#endif // __TILE_H_
