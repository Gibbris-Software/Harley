#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "harley.h"
#include "situation.h"
#include "player.h"
#include "battle.h"
#include "overworld.h"


namespace Harley
{
    Harley::Harley(){
        SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO);
        IMG_Init(IMG_INIT_PNG);
        window = SDL_CreateWindow("Harley", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
        SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, 0);
        SDL_RenderSetScale(renderer, 2, 2);

        currentPlayer = new Player ();

        battle = new Battle (&(*currentPlayer), "anais", &(*renderer));
        overworld = new Overworld (&(*currentPlayer), &(*renderer));

        currentSituation = overworld;
    }

    void Harley::mainloop(){
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
            currentSituation->update(SDL_GetTicks() - startTime);
            currentSituation->redraw(renderer);
            SDL_RenderPresent(renderer);
        }
    }
    
    void Harley::handleKeyDown(SDL_KeyboardEvent event){
        switch(event.keysym.sym){
            case SDLK_w:
                currentSituation->startUp();
                break;
            case SDLK_s:
                currentSituation->startDown();
                break;
            case SDLK_a:
                currentSituation->startLeft();
                break;
            case SDLK_d:
                currentSituation->startRight();
                break;
        }
    }
    
    void Harley::handleKeyUp(SDL_KeyboardEvent event){
        switch(event.keysym.sym){
            case SDLK_w:
                currentSituation->stopUp();
                break;
            case SDLK_s:
                currentSituation->stopDown();
                break;
            case SDLK_a:
                currentSituation->stopLeft();
                break;
            case SDLK_d:
                currentSituation->stopRight();
                break;
        }
    }
    
    void Harley::quit(){
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        delete overworld;
        delete currentPlayer;
        delete battle;
    }
}
