#ifndef __TILES_H_INCLUDED
#define __TILES_H_INCLUDED

#include <vector>
#include <string>

struct SDL_Surface;


class Tile {
    int width;
    int height;
    int pixels[];
  public:
    Tile(int, int);
    Tile(int, int, int[]);
    void draw(int, int, int[], SDL_Surface);
};

class Tileset {
    std::vector<Tile> tiles;
    std::string filename;
    std::vector<int> palette;
    int width;
    int height;
    Tileset(std::string, std::vector<Tile>, int[], int, int);
  public:
    Tileset(std::string, int, int);
    Tileset(int, int);
    Tileset(std::string);
    void save(std::string);
    void save();
    void export_img();
};

#endif // __TILES_H_INCLUDED

