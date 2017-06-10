#ifndef __OVERWORLD_H_
#define __OVERWORLD_H_

#include <string>

#include "sfml.h"
#include "area.h"
#include "tile.h"
#include "map.h"
#include "player.h"

namespace Harley {
    class Overworld : Area {
        Tileset tiles;
        Map map;

        bool movingRight;
        bool movingLeft;
        bool movingUp;
        bool movingDown;

        int speed;
        int multiplier;

		void startLeft();
		void startRight();
		void startUp();
		void startDown();
		void stopLeft();
		void stopRight();
		void stopUp();
		void stopDown();
        void slowDown();
        void speedUp();

      public:
        Overworld();
        void redraw(sf::RenderWindow&, Player& character);
		void update(Player& character, Game&);
		void handleKeyDown(sf::Event::KeyEvent);
		void handleKeyUp(sf::Event::KeyEvent);
    };
}

#endif // __OVERWORLD_H_
