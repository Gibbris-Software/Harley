#include "player.h"

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
        tile_x = 1600;
        tile_y = 1600;
        battle_x = 40;
        battle_y = 40;
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

    int Player::getBattleX()
    {
        return battle_x;
    }

    int Player::getBattleY() {
        return battle_y;
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
}
