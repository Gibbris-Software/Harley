#include "player.h"
#include "constants.h"

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
        tile_x = 629*TILE_SIZE;
        tile_y = 588*TILE_SIZE;
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
        sprite.setTexture(texture);
        sprite.setScale(SCALE, SCALE);
        animation_state = 0;
        //ability = new HealthRegenAbility ();
        //special_attack = new SpecialAttack ();
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

    int Player::getSpeed(){
        return BASE_SPEED;
    }

    int Player::getDiagonalSpeed(){
        return DIAGONAL_SPEED;
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
