#ifndef __CITY_H__
#define __CITY_H__

#include "area.h"
#include "tile.h"
#include "map.h"

namespace Harley {
    class City : public Area
    {
        public:
            City();
            virtual ~City();
            void redraw(sf::RenderWindow&, Player& character);
            void update(Player& character, Game&);
            void handleKeyDown(sf::Event::KeyEvent);
            void handleKeyUp(sf::Event::KeyEvent);
            void load(std::string, int, int);
        protected:
        private:
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
    };
}

#endif // __CITY_H__
