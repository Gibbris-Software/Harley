#include <string>
#include <iostream>
#include <SDL2/SDL.h>

#include "editor.h"
#include "tiles.h"


void Editor::setup(std::vector<std::string> args){
    if (args.size() == 1){
        this->tiles = new Tileset(args.at(0));
    } else if (args.size() == 2){
        this->tiles = new Tileset(std::stoi(args.at(0)), std::stoi(args.at(1)));
    }/* else if (args.size() == 3){
        this->tiles = new Tileset(args.at(0), std::stoi(args.at(1)), std::stoi(args.at(2)));
    }*/
    SDL_Init(SDL_INIT_VIDEO);
    this->window = SDL_CreateWindow("Tileset Editor", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
    this->surface = SDL_GetWindowSurface(this->window);
}

int Editor::run(){
    SDL_FillRect(this->surface, NULL, SDL_MapRGB(this->surface->format, 64, 160, 0));
    SDL_UpdateWindowSurface(this->window);
    SDL_Delay(2000);
    return 0;
}

void Editor::cleanup(){
    SDL_DestroyWindow(this->window);
}
