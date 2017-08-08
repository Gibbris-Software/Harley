#include <iostream>
#include "sfml.h"
#include "overworld.h"
#include "constants.h"
#include "game.h"

namespace Harley
{
    void Overworld::setup(possum::Game& game)
    {
        if (!created){
            tiles.loadFromFile("Resources/anais.png");
            tiles.setSmooth(false);
            possum::Entity& tileset = scene.create(MAP, 0, 0, 0, tiles);
            tileset.sprite.setScale(SCALE, SCALE);
            tileset.sprite.setOrigin(0, 0);
            Map::load_chunks(tileset, "Resources/beauve", 1440, 960, 3, 3);
            // map.load("npc_test");
            movingRight = false;
            movingUp = false;
            movingLeft = false;
            movingDown = false;
            speed = BASE_SPEED;
        }
        game.setScene(&scene);
        // npcs.push_back(new NPC("mia"));
    }

/*    void Overworld::redraw(sf::RenderWindow& window, Player& character)
    {
        // character->next_animation();
        sf::Sprite sprite = character.direction(movingRight-movingLeft, movingDown-movingUp);
        sprite.setPosition((character.getTileX()-centerX+SCREEN_WIDTH/2)*SCALE, (character.getTileY()-centerY+SCREEN_HEIGHT/2)*SCALE);
        window.draw(sprite);
    }

    void Overworld::startUp(){
        movingUp = true;
        movingDown = false;
        if (movingLeft || movingRight) {
            speed = DIAGONAL_SPEED;
        }
    }

    void Overworld::startDown(){
        movingDown = true;
        movingUp = false;
        if (movingLeft || movingRight) {
            speed = DIAGONAL_SPEED;
        }
    }

    void Overworld::startLeft(){
        movingLeft = true;
        movingRight = false;
        if (movingUp || movingDown) {
            speed = DIAGONAL_SPEED;
        }
    }

    void Overworld::startRight ()
    {
        movingRight = true;
        movingLeft = false;
        if (movingUp || movingDown) {
            speed = DIAGONAL_SPEED;
        }
    }

    void Overworld::stopUp(){
        movingUp = false;
        speed = BASE_SPEED;
    }

    void Overworld::stopDown(){
        movingDown = false;
        speed = BASE_SPEED;
    }

    void Overworld::stopLeft(){
        movingLeft = false;
        speed = BASE_SPEED;
    }

    void Overworld::stopRight ()
    {
        movingRight = false;
        speed = BASE_SPEED;
    }

    void Overworld::slowDown(){
        multiplier = 1;
    }

    void Overworld::speedUp(){
        multiplier = 2;
    }

    void Overworld::handleKeyDown(sf::Event::KeyEvent event){
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
            case sf::Keyboard::LShift:
                speedUp();
        }
    }

    void Overworld::handleKeyUp(sf::Event::KeyEvent event){
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
                slowDown();
        }
    }

    void Overworld::update(Player& character, Game& game){
        if (movingUp) {
            character.moveUpTile (speed);
        } else if (movingDown) {
            character.moveDownTile (speed);
        }

        if (movingRight) {
            character.moveRightTile (speed);
        } else if (movingLeft) {
            character.moveLeftTile (speed);
        }
    }*/
}

