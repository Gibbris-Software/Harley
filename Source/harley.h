#infdef __HARLEY_H_
#define __HARLEY_H_

#include "player.h"
#include "situation.h"

namespace Harley
{
    public class Harley
    {
        SDL_Window *window;
        SDL_Surface *surface;
        Situation *battle;
        Situation *overworld;
        Player *currentPlayer;
        Situation *currentSituation;

        void handleKeyDown(SDL_KeyEvent);
        void handleKeyUp(SDL_KeyEvent);

      public:
        Harley ();

        void mainloop();
    }
}

#endif // __HARLEY_H_
