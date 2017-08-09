#ifndef __OVERWORLD_H_
#define __OVERWORLD_H_

#include <string>

#include "sfml.h"
#include "area.h"
#include "tile.h"
#include "map.h"
#include "player.h"
#include "npc.h"

namespace Harley {
    class Overworld {
        Player player;

        possum::Scene scene;
        bool created;
        sf::Texture tiles;

      public:
        Overworld(){};
        void setup(possum::Game&);
    };
}

#endif // __OVERWORLD_H_
