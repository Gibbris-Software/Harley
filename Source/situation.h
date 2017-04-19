#ifndef __SITUATION_H_
#define __SITUATION_H_

#include <SDL2/SDL.h>

namespace Harley
{
	class Situation
	{
      public:
		virtual void redraw(SDL_Renderer);
		virtual void startLeft();
		virtual void startRight();
		virtual void startUp();
		virtual void startDown();
		virtual void stopLeft();
		virtual void stopRight();
		virtual void stopUp();
		virtual void stopDown();
		virtual void update();
	}
}

#endif // __SITUATION_H

