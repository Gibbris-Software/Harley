#ifndef HARLEY_LITTLEOAK
#define HARLEY_LITTLEOAK

#include "possum/possum.h"
#include "sfml.h"
#include "player.h"

namespace Harley {
    class LittleOak {
        sf::Texture tiles;
        sf::Texture mia_texture;
      public:
        std::shared_ptr<possum::Scene> scene;
        LittleOak(): scene(0) {};
        void setup(possum::Game&, Player);
    };
}

#endif // HARLEY_LITTLEOAK
