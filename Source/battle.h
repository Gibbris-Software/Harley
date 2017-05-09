#ifndef __BATTLE_H_
#define __BATTLE_H_

#include <string>

#include "sfml.h"
#include "situation.h"
#include "tile.h"
#include "map.h"
#include "player.h"

namespace Harley {
    class Battle : public Situation {
        sf::Texture background_texture;
        sf::Sprite background;
        Map *map;
        Player *character;

        bool movingRight;
        bool movingLeft;
        bool jumping;
        bool falling;
        int yspeed;

        int x, y;

      public:
        Battle(Player*, std::string);
        void redraw(sf::RenderWindow&);
		void startLeft();
		void startRight();
		void startUp();
		void startDown();
		void stopLeft();
		void stopRight();
		void stopUp();
		void stopDown();
		void update();
    };
}

#endif // __BATTLE_H_
