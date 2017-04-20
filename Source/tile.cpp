#include "tile.h"
#include "constants.h"
#include "sdl_include.h"

namespace Harley
{
	Tileset::Tileset (std::string location, SDL_Renderer* renderer)
    {
        SDL_Surface *surface = IMG_Load(location.c_str());
        width = surface->w / TILE_SIZE;
        height = surface->w / TILE_SIZE;
        sheet = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
    }

    void Tileset::renderTile(int which, int x, int y, SDL_Renderer* renderer){
        int tx = which % width;
        int ty = which / height;
        SDL_Rect clip = {tx * TILE_SIZE, ty * TILE_SIZE, TILE_SIZE, TILE_SIZE};
        SDL_Rect draw = {x*TILE_SIZE, y*TILE_SIZE, TILE_SIZE, TILE_SIZE};
        
        SDL_RenderCopy(renderer, sheet, &clip, &draw);
    }
}

