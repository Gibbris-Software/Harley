#ifndef __HOUSE_H_
#define __HOUSE_H_

#include "sfml.h"
#include "area.h"
#include "tile.h"
#include "map.h"

namespace Harley {
    class House : public Area
    {
        public:
            House();
            virtual ~House();
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

#endif // __HOUSE_H_
