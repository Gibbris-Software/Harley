#ifndef __EDITOR_H_INCLUDED
#define __EDITOR_H_INCLUDED

#include <SDL2/SDL.h>
#include <string>
#include <vector>

class Tileset;


class Editor {
    SDL_Window *window;
    SDL_Surface *surface;
    Tileset *tiles;
  public:
    void setup(std::vector<std::string>);
    int run();
    void cleanup();
};

#endif // __EDITOR_H_INCLUDED 
