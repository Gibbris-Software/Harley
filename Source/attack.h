#ifndef __ATTACK_H_
#define __ATTACK_H_

namespace Harley
{
    class Attack
    {
        int x;
        int y;
        int radius;
        int strength;
      public:
        Attack(int, int, int, int);
        int getX();
        int getY();
        int getRadius();
        int getStrength();
        virtual void update() = 0;
    };
}

#endif // __ATTACK_H_
