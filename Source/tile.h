#ifndef __TILE_H_
#define __TILE_H_

#include <string>
#include <SDL2/SDL.h>

namespace Harley {
    class Tileset {
        SDL_Texture *sheet;
        int width;
        int height;
      public:
        Tileset(std::string, SDL_Renderer*);
        void renderTile(int, int, int, SDL_Renderer*);
    };
}

#endif // __TILE_H_
