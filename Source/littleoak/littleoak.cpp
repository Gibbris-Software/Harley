#include "littleoak/littleoak.h"
#include "harley/constants.h"
#include "harley/map.h"
#include "littleoak/mia.h"

namespace Harley {
    void LittleOak::setup(possum::Game& game, Player player){
       possum::Scene& scene = *game.newScene();
       tiles.loadFromFile("Resources/anais.png");
       tiles.setSmooth(false);
       possum::Entity& map = scene.create(MAP, 0, 0, 0, tiles);
       Map::load(map, "littleoak");
       createMia(mia_texture, scene);
       player.create(game, scene);
       game.setScene(game.numScenes()-1);
    }
}
