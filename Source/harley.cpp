#include <SDL2/SDL.h>

#include "harley.h"
#include "situation.h"
#include "player.h"
#include "battle.h"
#include "overworld.h"


namespace Harley
{
    Harley::Harley(){
        SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO);
        window = SDL_CreateWindow("Harley", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
        surface = SDL_GetWindowSurface(window);

        currentPlayer = new Player ();

        battle = new Battle (currentPlayer);
        overworld = new Overworld (currentPlayer);

        currentSituation = overworld;
    }

    Harley::mainloop(){
        SDL_Event e;
        bool running = true;
        Uint32 startTime;
        while (running){
            startTime = SDL_GetTicks();
            while (SDL_PollEvent(&e) != 0){
                switch (e.type){
                    case SDL_QUIT:
                        running = false;
                        break;
                    case SDL_KEYDOWN:
                        handleKeyDown(e.key);
                        break;
                    case SDL_KEYUP:
                        handleKeyUp(e.key);
                        break;
                }
            }
            currentSituation.update(SDL_GetTicks() - startTime);
            currentSituation.redraw(surface);
            SDL_UpdateWindowSurface(window);
        }
    }
    
    Harley::onKeyDown(SDL_KeyEvent event){
        switch(event.keysym.sym){
            case SDLK_w:
                currentSituation.startUp();
                break;
            case SDLK_s:
                currentSituation.startDown();
                break;
            case SDLK_a:
                currentSituation.startLeft();
                break;
            case SDLK_d:
                currentSituation.startRight();
                break;
        }
    }
    
    Harley::onKeyUp(SDL_KeyEvent event){
        switch(event.keysym.sym){
            case SDLK_w:
                currentSituation.stopUp();
                break;
            case SDLK_s:
                currentSituation.stopDown();
                break;
            case SDLK_a:
                currentSituation.stopLeft();
                break;
            case SDLK_d:
                currentSituation.stopRight();
                break;
        }
    }
    
    Harley::quit(){
        SDL_DestroyWindow(window);
        delete overworld;
        delete currentPlayer;
        delete battle;
}
