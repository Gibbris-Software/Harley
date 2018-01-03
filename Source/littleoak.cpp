#include "littleoak.h"
#include "constants.h"
#include "map.h"
#include <iostream>


void redrawMia(possum::Entity& entity, possum::Scene& scene, possum::Game& game, void* data) {
    sf::RenderWindow& window = *(sf::RenderWindow*)(data);
    entity.sprite.setPosition(entity.x*SCALE, entity.y*SCALE);
    window.draw(entity.sprite);
}


void walkDown(possum::Entity&, possum::Scene&, possum::Game&, void*);
void walkUp(possum::Entity&, possum::Scene&, possum::Game&, void*);
void walkLeft(possum::Entity&, possum::Scene&, possum::Game&, void*);
void walkRight(possum::Entity&, possum::Scene&, possum::Game&, void*);

void update(possum::Entity& entity){
    entity.state["can_talk"] = 0;
}

void walkDown(possum::Entity& entity, possum::Scene& scene, possum::Game& game, void* data){
    sf::Time time = *(sf::Time*)(data);
    update(entity);
    entity.y += time.asSeconds()*60;
    if (entity.y >= 12 * TILE_SIZE) {
        entity.register_event(possum::UPDATE, walkRight);
    }
}

void walkUp(possum::Entity& entity, possum::Scene& scene, possum::Game& game, void* data) {
    sf::Time time = *(sf::Time*)(data);
    update(entity);
    entity.y -= time.asSeconds()*60;
    if (entity.y <= 6 * TILE_SIZE) {
        entity.register_event(possum::UPDATE, walkLeft);
    }
}

void walkRight(possum::Entity& entity, possum::Scene& scene, possum::Game& game, void* data){
    sf::Time time = *(sf::Time*)(data);
    update(entity);
    entity.x += time.asSeconds()*60;
    if (entity.x >= 10 * TILE_SIZE) {
        entity.register_event(possum::UPDATE, walkUp);
    }
}

void walkLeft(possum::Entity& entity, possum::Scene& scene, possum::Game& game, void* data) {
    sf::Time time = *(sf::Time*)(data);
    update(entity);
    entity.x -= time.asSeconds()*60;
    if (entity.x <= 2 * TILE_SIZE) {
        entity.register_event(possum::UPDATE, walkDown);
    }
}


void redrawMiaDialogue1(possum::Entity& entity, possum::Scene& scene, possum::Game& game, void* data) {
    sf::RenderWindow& window = *(sf::RenderWindow*)(data);
    sf::RectangleShape background;
    background.setSize(sf::Vector2f(game.state["width"], 40));
    background.setPosition(game.state["x"], game.state["y"] + game.state["height"] - 40);
    background.setFillColor(sf::Color(0, 0, 0, 127));
    window.draw(background);
    sf::Text text;
    text.setFont(game.getFont("Resources/dialogue.ttf"));
    text.setString("Mia: Hello!");
    text.setCharacterSize(30);
    text.setPosition(game.state["x"] + 5, game.state["y"] + game.state["height"] - 35);
    text.setFillColor(sf::Color(255, 255, 255, 255));
    window.draw(text);
}

void keyPress(possum::Entity& entity, possum::Scene& scene, possum::Game& game, void* data) {
    sf::Event::KeyEvent& event = *(sf::Event::KeyEvent*)(data);
    if (entity.state["can_talk"]) {
        if (event.code == sf::Keyboard::Space) {
            possum::Entity& dialogue = scene.create(DIALOGUE, 0, 0, 0, entity.texture);
            dialogue.register_event(possum::REDRAW, redrawMiaDialogue1);
        }
    }
}

void collisionMia(possum::Entity& entity, possum::Scene& scene, possum::Game& game, void* data) {
    possum::Entity& other = *(possum::Entity*)(data);
    if (other.type == PLAYER){
        entity.state["can_talk"] = 1;
    }
}

void createMia(sf::Texture& mia_texture, possum::Scene& scene) {
    mia_texture.loadFromFile("Resources/mia.png");
    mia_texture.setSmooth(false);
    possum::Entity& mia = scene.create(NPC, 2*TILE_SIZE, 6*TILE_SIZE, 2*TILE_SIZE, mia_texture);
    mia.sprite.setScale(SCALE, SCALE);
    mia.register_event(possum::REDRAW, redrawMia);
    mia.register_event(possum::UPDATE, walkDown);
    mia.register_event(possum::KEY_DOWN, keyPress);
    mia.register_event(possum::COLLISION, collisionMia);
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
