#include "enemytest.h"
#include "constants.h"

namespace Harley{
    EnemyTest::EnemyTest(int x, int y)
    {
        Attack attack;
        attack.x = x;
        attack.y = y;
        attack.radius = 8;
        attack.strength = 2;
        attack.type = 0;
        attacks.push_back(attack);
        texture.loadFromFile("Resources/enemytest.png");
        texture.setSmooth(false);
        sprite.setTexture(texture);
        sprite.setScale(SCALE, SCALE);
    }

    EnemyTest::~EnemyTest()
    {
        //dtor
    }

    void EnemyTest::update(){

    }

    void EnemyTest::redraw(sf::RenderWindow& window){
        Attack attack = attacks.at(0);
        sprite.setPosition((attack.x - 8)*SCALE, (attack.y - 8)*SCALE);
        window.draw(sprite);
    }
}
