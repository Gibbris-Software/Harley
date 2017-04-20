#ifndef __BATTLE_H_
#define __BATTLE_H_

#include <string>

#include "situation.h"
#include "tile.h"
#include "map.h"
#include "player.h"

namespace Harley {
    class Battle : public Situation {
        Tileset *tiles;
        Map *map;
        Player *character;
        
        bool movingRight;
        bool movingLeft;
        bool movingUp;
        bool movingDown;
        
        int speed;
      
      public:
        Battle(Player*, std::string, SDL_Renderer*);
        void redraw(SDL_Renderer*);
		void startLeft();
		void startRight();
		void startUp();
		void startDown();
		void stopLeft();
		void stopRight();
		void stopUp();
		void stopDown();
		void update(Uint32);
    };
}       

#endif // __BATTLE_H_