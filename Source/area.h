#ifndef __SITUATION_H_
#define __SITUATION_H_

#include "sfml.h"

namespace Harley
{
    class Game;
    class Player;

	class Area
	{
      public:
		virtual void redraw(sf::RenderWindow&, Player&) = 0;
		virtual void update(Player&, Game&) = 0;
		virtual void handleKeyDown(sf::Event::KeyEvent) = 0;
		virtual void handleKeyUp(sf::Event::KeyEvent) = 0;
		virtual ~Area(){};
	};
}

#endif // __SITUATION_H

