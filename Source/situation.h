#ifndef __SITUATION_H_
#define __SITUATION_H_

#include "sfml.h"

namespace Harley
{
	class Situation
	{
      public:
		virtual void redraw(sf::RenderWindow&) = 0;
		virtual void startLeft() = 0;
		virtual void startRight() = 0;
		virtual void startUp() = 0;
		virtual void startDown() = 0;
		virtual void stopLeft() = 0;
		virtual void stopRight() = 0;
		virtual void stopUp() = 0;
		virtual void stopDown() = 0;
		virtual void update() = 0;
	};
}

#endif // __SITUATION_H

