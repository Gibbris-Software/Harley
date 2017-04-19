#include <SDL2/SDL.h>

#include "battle.h"

namespace Harley
{
    Battle::Battle (Player player, std::string where)
    {
        tiles = new Tileset ("Resources/anais.png");
        map = new Map ("Resources/anais.map");
        character = player;
        movingRight = false;
        movingUp = false;
        movingLeft = false;
        movingDown = false;
    }

    Battle::redraw(SDL_Renderer renderer)
    {
        //cr.Scale (2, 2);
        //cr.Antialias = Cairo.Antialias.None;

        //for (int i = 0; i < 20; i++) {
        //    for (int j = 0; j < 15; j++) {
        //        Tile tile = tiles.Tile (map.Tile (i, j));
        //        cr.Rectangle (i * 16, j * 16, 16, 16);
        //        cr.SetSourceSurface(tile.Surface, i*16, j*16);
        //        cr.Fill ();
        //    }
        //}

        //cr.Arc (character.BattleX, character.BattleY, 8, 0, Math.PI * 2);

        //cr.SetSourceRGB (0.1, 0.2, 0.75);
        //cr.Fill ();

        //((IDisposable) cr.GetTarget()).Dispose();
        //((IDisposable) cr).Dispose();
    }

    void Battle::startUp(){
        movingUp = true;
        movingDown = false;
        if (movingLeft || movingRight) {
            speed = 2;
        }
    }

    void Battle::startDown(){
        movingDown = true;
        movingUp = false;
        if (movingLeft || movingRight) {
            speed = 2;
        }
    }

    void Battle::startLeft(){
        movingLeft = true;
        movingRight = false;
        if (movingUp || movingDown) {
            speed = 2;
        }
    }

    void Battle::startRight ()
    {
        movingRight = true;
        movingLeft = false;
        if (movingUp || movingDown) {
            speed = 2;
        }
    }

    void Battle::stopUp(){
        movingUp = false;
        speed = 3;
    }

    void Battle::stopDown(){
        movingDown = false;
        speed = 3;
    }

    void Battle::stopLeft(){
        movingLeft = false;
        speed = 3;
    }

    void Battle::stopRight ()
    {
        movingRight = false;
        speed = 3;
    }

    void Battle::update(){
        if (movingUp) {
            character.moveUpBattle (speed);
        } else if (movingDown) {
            character.moveDownBattle (speed);
        }

        if (movingRight) {
            character.moveRightBattle (speed);
        } else if (movingLeft) {
            character.m (speed);
        }
    }
}

