#ifndef __CONSTANTS_H_
#define __CONSTANTS_H_

#define TILE_SIZE 16

#define TILE_WIDTH 20
#define TILE_HEIGHT 16

#define SCREEN_WIDTH (TILE_SIZE * TILE_WIDTH)
#define SCREEN_HEIGHT (TILE_SIZE * TILE_HEIGHT)

#define SCALE 2

#define PLAYER_HEIGHT 24

#define BASE_SPEED 3
#define DIAGONAL_SPEED 2

enum EntityTypes {
    MAP,
    PLAYER,
    ENEMY,
    NPC,
    OBSTACLE,
    DIALOGUE,
};

#define BEGIN_OBSTACLE 128

#define PAUSE USER_EVENT_1
#define UNPAUSE USER_EVENT_2

#endif // __CONSTANTS_H_
