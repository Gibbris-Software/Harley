#ifndef __ENEMYTEST_H_
#define __ENEMYTEST_H_

#include "enemy.h"
#include "attack.h"
#include "sfml.h"

namespace Harley {
    class EnemyTest : public Enemy
    {
        public:
            EnemyTest(int x, int y);
            virtual ~EnemyTest();
            void update();
            void redraw(sf::RenderWindow&);
        protected:
        private:
            sf::Texture texture;
            sf::Sprite sprite;
    };
}

#endif // __ENEMYTEST_H_
