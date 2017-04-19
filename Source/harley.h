#ifndef __HARLEY_H_
#define __HARLEY_H_

#include <SDL2/SDL.h>

#include "player.h"
#include "situation.h"

namespace Harley
{
    class Harley
    {
        SDL_Window *window;
        SDL_Renderer *renderer;
        Situation *battle;
        Situation *overworld;
        Player *currentPlayer;
        Situation *currentSituation;

        void handleKeyDown(SDL_KeyboardEvent);
        void handleKeyUp(SDL_KeyboardEvent);

      public:
        Harley ();

        void mainloop();
        void quit();
    };
}

#endif // __HARLEY_H_
