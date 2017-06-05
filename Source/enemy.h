#ifndef __ENEMY_H_
#define __ENEMY_H_

#include <vector>

#include "attack.h"
#include "sfml.h"

namespace Harley {
    class Enemy
    {
        public:
            Enemy();
            virtual ~Enemy();
            std::vector<Attack> getAttacks();
            virtual void update() = 0;
            virtual void redraw(sf::RenderWindow&) = 0;
        protected:
            std::vector<Attack> attacks;
        private:
    };
}

#endif // __ENEMY_H_
