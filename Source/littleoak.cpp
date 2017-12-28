#include "littleoak.h"
#include "constants.h"
#include "map.h"


void redrawMia(possum::Entity& entity, possum::Scene& scene, possum::State& gameState, void* data) {
    sf::RenderWindow& window = *(sf::RenderWindow*)(data);
    entity.sprite.setPosition(entity.x*SCALE, entity.y*SCALE);
    window.draw(entity.sprite);
}


void walkDown(possum::Entity&, possum::Scene&, possum::State&, void*);
void walkUp(possum::Entity&, possum::Scene&, possum::State&, void*);
void walkLeft(possum::Entity&, possum::Scene&, possum::State&, void*);
void walkRight(possum::Entity&, possum::Scene&, possum::State&, void*);

void walkDown(possum::Entity& entity, possum::Scene& scene, possum::State& state, void* data){
    sf::Time time = *(sf::Time*)(data);
    entity.y += time.asSeconds()*60;
    if (entity.y >= 12 * TILE_SIZE) {
        entity.register_event(possum::UPDATE, walkRight);
    }
}

void walkUp(possum::Entity& entity, possum::Scene& scene, possum::State& gameState, void* data) {
    sf::Time time = *(sf::Time*)(data);
    entity.y -= time.asSeconds()*60;
    if (entity.y <= 6 * TILE_SIZE) {
        entity.register_event(possum::UPDATE, walkLeft);
    }
}

void walkRight(possum::Entity& entity, possum::Scene& scene, possum::State& state, void* data){
    sf::Time time = *(sf::Time*)(data);
    entity.x += time.asSeconds()*60;
    if (entity.x >= 10 * TILE_SIZE) {
        entity.register_event(possum::UPDATE, walkUp);
    }
}

void walkLeft(possum::Entity& entity, possum::Scene& scene, possum::State& gameState, void* data) {
    sf::Time time = *(sf::Time*)(data);
    entity.x -= time.asSeconds()*60;
    if (entity.x <= 2 * TILE_SIZE) {
        entity.register_event(possum::UPDATE, walkDown);
    }
}

void createMia(sf::Texture& mia_texture, possum::Scene& scene) {
    mia_texture.loadFromFile("Resources/mia.png");
    mia_texture.setSmooth(false);
    possum::Entity& mia = scene.create(NPC, 2*TILE_SIZE, 6*TILE_SIZE, TILE_SIZE, mia_texture);
    mia.sprite.setScale(SCALE, SCALE);
    mia.register_event(possum::REDRAW, redrawMia);
    mia.register_event(possum::UPDATE, walkDown);
    // mia.register_event(possum::COLLISION, collisionMia);
}

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
