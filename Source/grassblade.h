#ifndef GRASSBLADE_H
#define GRASSBLADE_H

#include <enemy.h>
#include <attack.h>


class GrassBlade : public Enemy, public Attack
{
    public:
        GrassBlade(int x, int y): Enemy(x, y, 2), Attack(x, y, 2, 1);
        void update(Map, Player*);
        void update();
    protected:
    private:
};

#endif // GRASSBLADE_H
