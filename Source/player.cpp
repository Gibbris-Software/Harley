#include "player.h"
#include "constants.h"
#include <string>
#include <math.h>
#include <lua.h>


enum directions {
    UP,
    DOWN,
    LEFT,
    RIGHT,
};

//Event callbacks
void redraw_player(possum::Entity& entity, possum::Scene& scene, possum::Game& game, void* data){
    sf::RenderWindow& window = *(sf::RenderWindow*)(data);
    entity.sprite.setPosition(entity.x*SCALE, entity.y*SCALE);
    window.draw(entity.sprite);
}

void update_player(possum::Entity& entity, possum::Scene& scene, possum::Game& game, void* data){
    sf::Time time = *(sf::Time*)(data);
    game.state["tileX"] = entity.x;
    game.state["tileY"] = entity.y;
    if (entity.state["moving"] != 0){
        int a = entity.state["animationState"] + 1;
        if (a == 2){
            a = 0;
        }
        entity.state["animationState"] = a;
        std::string prefix = std::to_string(entity.state["direction"])+"_"+std::to_string(a);
        entity.sprite.setTextureRect(sf::IntRect(entity.state[prefix+"_x"], entity.state[prefix+"_y"], 16, 24));
        switch(entity.state["direction"]){
            case UP:
                entity.y -= time.asSeconds()*60;
                break;
            case DOWN:
                entity.y += time.asSeconds()*60;
                break;
            case LEFT:
                entity.x -= time.asSeconds()*60;
                break;
            case RIGHT:
                entity.x += time.asSeconds()*60;
                break;
        }
    }
    // std::cout << gameState.get("width") << std::endl;
    game.state["x"] = entity.x*SCALE - game.state["width"]/2;
    game.state["y"] = entity.y*SCALE - game.state["height"]/2;
}

void handle_keydown_player(possum::Entity& entity, possum::Scene& scene, possum::Game& game, void* data){
    sf::Event::KeyEvent event = *(sf::Event::KeyEvent*)(data);
    switch (event.code){
        case sf::Keyboard::S:
            entity.state["moving"] = 1;
            entity.state["direction"] = DOWN;
            break;
        case sf::Keyboard::W:
            entity.state["moving"] = 1;
            entity.state["direction"] = UP;
            break;
        case sf::Keyboard::A:
            entity.state["moving"] = 1;
            entity.state["direction"] = LEFT;
            break;
        case sf::Keyboard::D:
            entity.state["moving"] = 1;
            entity.state["direction"] = RIGHT;
            break;
        default:
            break;
    }
}

void handle_keyup_player(possum::Entity& entity, possum::Scene& scene, possum::Game& game, void* data){
    sf::Event::KeyEvent event = *(sf::Event::KeyEvent*)(data);
    switch (event.code){
        case sf::Keyboard::S:
        case sf::Keyboard::A:
        case sf::Keyboard::W:
        case sf::Keyboard::D:
            entity.state["moving"] = 0;
            break;
        default:
            break;
    }
}

void collide_player(possum::Entity& entity, possum::Scene& scene, possum::Game& game, void* data){
    possum::Entity& other = *(possum::Entity*)(data);
    if (other.type == OBSTACLE){
        float factor = pow(other.radius + entity.radius, 2)/(pow(other.x-entity.x, 2)+pow(other.y-entity.y, 2));
        entity.x = other.x + factor * (entity.x - other.x);
        entity.y = other.y + factor * (entity.y - other.y);
    }
}

namespace Harley
{
    Player::Player()
    {
        hp = 100;
        stamina = 100;
        attack_strength = 12;
        defence = 5;
        weight = 9;
        max_weight_load = 0;
        tile_x = 17*TILE_SIZE;
        tile_y = 6*TILE_SIZE;
        battle_x = 40;
        battle_y = 40;
        texture.loadFromFile("Resources/HarleyBeta.png");
        front[0] = sf::IntRect(0, 0, 16, 24);
        front[1] = sf::IntRect(16, 0, 16, 24);
        back[0] = sf::IntRect(0, 24, 16, 24);
        back[1] = sf::IntRect(16, 24, 16, 24);
        left[0] = sf::IntRect(32, 24, 16, 24);
        left[1] = sf::IntRect(48, 24, 16, 24);
        right[0] = sf::IntRect(32, 0, 16, 24);
        right[1] = sf::IntRect(48, 0, 16, 24);
        animation_state = 0;
        multiplier = 1;
        //ability = new HealthRegenAbility ();
        //special_attack = new SpecialAttack ();
    }

    void Player::create(possum::Game& game, possum::Scene& scene){
        possum::Entity& entity = scene.create(PLAYER, tile_x, tile_y, TILE_SIZE, game.getTexture("Resources/HarleyBeta.png"));
        entity.sprite.setScale(SCALE, SCALE);
        entity.sprite.setOrigin(8, 16);
        entity.sprite.setTextureRect(sf::IntRect(0, 0, 16, 24));
        entity.register_event(possum::REDRAW, redraw_player);
        entity.register_event(possum::UPDATE, update_player);
        entity.register_event(possum::KEY_DOWN, handle_keydown_player);
        entity.register_event(possum::KEY_UP, handle_keyup_player);
        entity.register_event(possum::COLLISION, collide_player);
        entity.state["moving"] = 0;
        entity.state["animationState"] = 0;
        entity.state["direction"] = DOWN;
        entity.state[std::to_string(DOWN)+"_0_x"] = 0;
        entity.state[std::to_string(DOWN)+"_0_y"] = 0;
        entity.state[std::to_string(DOWN)+"_1_x"] = 16;
        entity.state[std::to_string(DOWN)+"_1_y"] = 0;
        entity.state[std::to_string(UP)+"_0_x"] = 0;
        entity.state[std::to_string(UP)+"_0_y"] = 24;
        entity.state[std::to_string(UP)+"_1_x"] = 16;
        entity.state[std::to_string(UP)+"_1_y"] = 24;
        entity.state[std::to_string(LEFT)+"_0_x"] = 32;
        entity.state[std::to_string(LEFT)+"_0_y"] = 24;
        entity.state[std::to_string(LEFT)+"_1_x"] = 48;
        entity.state[std::to_string(LEFT)+"_1_y"] = 24;
        entity.state[std::to_string(RIGHT)+"_0_x"] = 32;
        entity.state[std::to_string(RIGHT)+"_0_y"] = 0;
        entity.state[std::to_string(RIGHT)+"_1_x"] = 48;
        entity.state[std::to_string(RIGHT)+"_1_y"] = 0;
    }


    void Player::attack()
    {
        /* To be implemented. */
    }

    void Player::strike()
    {
        /* To be implemented. */
    }

    void Player::special()
    {
        /* To be implemented. */
    }

    void Player::block()
    {
        /* To be implemented. */
    }

    void Player::dealDamage(int damage)
    {
        /* To be implemented. */
    }

    int Player::getHealth()
    {
        return hp;
    }

    int Player::getStamina()
    {
        return stamina;
    }

    double Player::getSpeed(){
        return BASE_SPEED*multiplier;
    }

    double Player::getDiagonalSpeed(){
        return DIAGONAL_SPEED*multiplier;
    }

    void Player::speedUp(){
        multiplier = 1.5;
    }

    void Player::slowDown(){
        multiplier = 1.0;
    }

    int Player::getTileX()
    {
        return tile_x;
    }

    int Player::getTileY() {
        return tile_y;
    }

    void Player::startBattle()
    {
        /* To be implemented. */
    }

    void Player::moveRightBattle(int distance){
        battle_x += distance;
    }

    void Player::moveLeftBattle(int distance){
        battle_x -= distance;
    }

    void Player::moveUpBattle(int distance){
        battle_y -= distance;
    }

    void Player::moveDownBattle(int distance){
        battle_y += distance;
    }

    void Player::moveRightTile(int distance){
        tile_x += distance;
    }

    void Player::moveLeftTile(int distance){
        tile_x -= distance;
    }

    void Player::moveUpTile(int distance){
        tile_y -= distance;
    }

    void Player::moveDownTile(int distance){
        tile_y += distance;
    }

    void Player::nextAnimation(){
        animation_state += 1;
        if (animation_state >= 2){
            animation_state = 0;
        }
    }

    sf::Sprite Player::direction(int x, int y){
        if (x > 0){
            sprite.setTextureRect(right[animation_state]);
        } else if (x < 0){
            sprite.setTextureRect(left[animation_state]);
        } else if (y < 0){
            sprite.setTextureRect(back[animation_state]);
        } else {
            sprite.setTextureRect(front[animation_state]);
        }
        return sprite;
    }
}
