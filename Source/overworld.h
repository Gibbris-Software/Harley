#ifndef __OVERWORLD_H_
#define __OVERWORLD_H_

#include <string>

#include "sfml.h"
#include "area.h"
#include "tile.h"
#include "map.h"
#include "player.h"
#include "npc.h"

namespace Harley {
    class Overworld {
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
        std::vector<NPC> npcs;
        possum::Scene scene;
        bool created;

      public:
        Overworld(){};
        void setup(possum::Game&);
    };
}

#endif // __OVERWORLD_H_
