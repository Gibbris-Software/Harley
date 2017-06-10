#ifndef __BATTLE_H_
#define __BATTLE_H_

#include <string>
#include <vector>

#include "sfml.h"
#include "area.h"
#include "tile.h"
#include "map.h"
#include "enemy.h"


namespace Harley {
    class Battle : public Area {
        sf::Texture background_texture;
        sf::Sprite background;
        Map tile_map;

        bool movingRight;
        bool movingLeft;
        bool jumping;
        bool falling;
        int yspeed;

        double x, y;

        std::vector<Enemy*> enemies;

		void startLeft();
		void startRight();
		void startUp();
		void startDown();
		void stopLeft();
		void stopRight();
		void stopUp();
		void stopDown();
        void counter();
      public:
        Battle(){};
        void load(std::string);
        void redraw(sf::RenderWindow&, Player&);
		void update(Player&, Game&);
		void handleKeyDown(sf::Event::KeyEvent);
		void handleKeyUp(sf::Event::KeyEvent);
		~Battle(){};
    };
}

#endif // __BATTLE_H_
