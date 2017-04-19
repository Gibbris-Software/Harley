#include <SDL2/SDL.h>

void main(){
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
    SDL_Delay(2000);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
