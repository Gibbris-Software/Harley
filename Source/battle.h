#ifndef __BATTLE_H_
#define __BATTLE_H_

#include <string>

#include "situation.h"
#include "tiles.h"
#include "map.h"

namespace Harley {
    class Battle : public Situation {
        Tileset tiles;
        Map map;
        Player *character;
        
        bool movingRight;
        bool movingLeft;
        bool movingUp;
        bool movingDown;
        
        int speed;
      
      public:
        Battle(Player, std::string);
    }
}       

#endif // __BATTLE_H_
