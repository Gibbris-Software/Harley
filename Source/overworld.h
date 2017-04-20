#ifndef __OVERWORLD_H_
#define __OVERWORLD_H_

#include <string>
#include "sdl_include.h"

#include "situation.h"
#include "tile.h"
#include "map.h"
#include "player.h"

namespace Harley {
    class Overworld : public Situation {
        Tileset *tiles;
        Map *map;
        Player *character;
        
        bool movingRight;
        bool movingLeft;
        bool movingUp;
        bool movingDown;
        
        int speed;
      
      public:
        Overworld(Player*, SDL_Renderer*);
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

#endif // __OVERWORLD_H_
