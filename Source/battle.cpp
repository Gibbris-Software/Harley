#include <iostream>

#include "sfml.h"

#include "battle.h"
#include "constants.h"
#include "enemytest.h"
#include "player.h"

namespace Harley
{
    void Battle::load(std::string where)
    {
        background_texture.loadFromFile("Resources/"+where+"_battle.png");
        background.setTexture(background_texture);
        background.setScale(SCALE, SCALE);
        tile_map.load(where + "_battle");
        for (int x = 0; x < tile_map.width(); x++){
            for (int y = 0; y < tile_map.height(); y++){
                if (tile_map.tileAt(x, y) == 2){
                    this->x = (double) x*TILE_SIZE;
                    this->y = (double) y*TILE_SIZE;
                }
            }
        }
        movingRight = false;
        movingLeft = false;
        enemies.push_back(new EnemyTest(this->x-TILE_SIZE, this->y));
    }

    void Battle::redraw(sf::RenderWindow &window, Player& character)
    {
        window.draw(background);

        sf::Sprite sprite = character.direction(movingRight-movingLeft, 0);
        sprite.setPosition(x*SCALE, (y+TILE_SIZE-PLAYER_HEIGHT)*SCALE);
        window.draw(sprite);

        for (std::vector<Enemy*>::iterator enemy = enemies.begin(); enemy < enemies.end(); enemy++){
            (*enemy)->redraw(window);
        }
    }

    void Battle::startUp(){
        jumping = true;
        if (!falling){
            falling = true;
            yspeed = -TILE_SIZE/2;
        }
    }

    void Battle::startDown(){
    }

    void Battle::startLeft(){
        movingLeft = true;
        movingRight = false;
    }

    void Battle::startRight ()
    {
        movingRight = true;
        movingLeft = false;
    }

    void Battle::stopUp(){
        jumping = false;
    }

    void Battle::stopDown(){
    }

    void Battle::stopLeft(){
        movingLeft = false;
    }

    void Battle::stopRight ()
    {
        movingRight = false;
    }

    void Battle::handleKeyDown(sf::Event::KeyEvent event){
        switch(event.code){
            case sf::Keyboard::W:
                startUp();
                break;
            case sf::Keyboard::S:
                startDown();
                break;
            case sf::Keyboard::A:
                startLeft();
                break;
            case sf::Keyboard::D:
                startRight();
                break;
        }
    }

    void Battle::counter(){

    }

    void Battle::handleKeyUp(sf::Event::KeyEvent event){
        switch(event.code){
            case sf::Keyboard::W:
                stopUp();
                break;
            case sf::Keyboard::S:
                stopDown();
                break;
            case sf::Keyboard::A:
                stopLeft();
                break;
            case sf::Keyboard::D:
                stopRight();
                break;
            case sf::Keyboard::LShift:
                counter();
        }
    }
    void Battle::update(Player& character, Game& game){
        if (falling){
            y += yspeed;
            yspeed += 1;
        }
        if (movingRight) {
            x += character.getSpeed();
        } else if (movingLeft) {
            x -= character.getSpeed();
        }
        int topleft = tile_map.tileAt(((int) x)/TILE_SIZE, ((int) y)/TILE_SIZE);
        int topright = tile_map.tileAt((((int) x)+TILE_SIZE-1)/TILE_SIZE, ((int) y)/TILE_SIZE);
        int bottomleft = tile_map.tileAt(((int) x)/TILE_SIZE, (((int) y)+TILE_SIZE-1)/TILE_SIZE);
        int bottomright = tile_map.tileAt((((int) x)+TILE_SIZE-1)/TILE_SIZE, (((int) y)+TILE_SIZE-1)/TILE_SIZE);
        if (topleft == 1 && bottomleft == 1){
            x = (((int) x)/TILE_SIZE+1)*TILE_SIZE;
            topleft = topright;
            bottomleft = bottomright;
        } else if (topright == 1 && bottomright == 1){
            x = (((int) x)/TILE_SIZE)*TILE_SIZE;
            topright = topleft;
            bottomright = bottomleft;
        }
        if (topleft == 1 && topright == 1){
            y = (((int) y)/TILE_SIZE+1)*TILE_SIZE;
            yspeed = 0;
        } else if ((bottomleft == 1 || bottomright == 1) && yspeed > 1){
            y = (((int) y)/TILE_SIZE)*TILE_SIZE;
            if (!jumping){
                yspeed = 0;
                falling = false;
            } else {
                yspeed = -TILE_SIZE/2;
            }
        }
        if (!falling && bottomleft != 1 && bottomright != 1){
            yspeed = 1;
            falling = true;
        }
        float center_x = x + TILE_SIZE/2;
        float center_y = y + TILE_SIZE/2;
        for (std::vector<Enemy*>::iterator enemy = enemies.begin(); enemy < enemies.end(); enemy++){
            (*enemy)->update();
            std::vector<Attack> attacks = (*enemy)->getAttacks();
            for (std::vector<Attack>::iterator attack = attacks.begin(); attack < attacks.end(); attack++){
                if ((pow(attack->x - center_x, 2) + pow(attack->y - center_y, 2)) < pow(attack->radius + TILE_SIZE/2, 2)){
                    exit(0);
                }
            }
        }
    }
}

