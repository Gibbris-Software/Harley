#ifndef __SDL_H_
#define __SDL_H_

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32)

#include <SDL.h>
#include <SDL_image.h>

#else

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#endif

#endif // __SDL_H_
