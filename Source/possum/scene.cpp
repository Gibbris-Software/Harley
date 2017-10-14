#include "scene.h"

namespace possum {
    Entity& Scene::create(int type, float x, float y, float radius, sf::Texture& texture){
        std::unique_ptr<Entity> e(new Entity(type, x, y, radius, texture));
//        e->type = type;
//        e->x = x;
//        e->y = y;
//        e->radius = radius;
//        e->dead = false;
//        e->texture.loadFromFile();
//        e->sprite.setTexture(texture);
        e->sprite.setOrigin(texture.getSize().x/2, texture.getSize().y/2);
//        for (int i = 0; i < 16; i++){
//            e->callbacks[i] = 0;
//        }
        entities.push_back(std::move(e));
        return *entities.back();
    }

}
