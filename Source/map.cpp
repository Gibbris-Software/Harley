#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "map.h"

namespace Harley
{
    Map::Map(){}

	void Map::load_chunks(std::string name, int width, int height, int chunk_width, int chunk_height)
    {
        std::string line;
        int tiles[height][width];
        int chunk_x_offset = 0;
        int chunk_y_offset = 0;
        int chunk_x_increment = width / chunk_width;
        int chunk_y_increment = height / chunk_height;
        for (int chunk_x = 1; chunk_x <= chunk_width; chunk_x++){
            chunk_y_offset = 0;
            for (int chunk_y = 1; chunk_y <= chunk_height; chunk_y++){
                std::stringstream file;
                file << name << "_" << chunk_x << "_" << chunk_y << ".csv";
                std::ifstream content(file.str().c_str());
                int y = 0;
                int x;
                while (std::getline(content, line)){
                    std::istringstream data(line);
                    x = 0;
                    int i;
                    char c;
                    while (data >> i){
                        tiles[chunk_y_offset+y][chunk_x_offset+x] = i;
                        x++;
                        data >> c;
                    }
                    y++;
                }
                chunk_y_offset += chunk_y_increment;
            }
            chunk_x_offset += chunk_x_increment;
        }
        for (int y = 0; y < height; y++){
            std::vector<int> row;
            for (int x = 0; x < width; x++){
                //std::cout << tiles[y][x] << ", ";
                row.push_back(tiles[y][x]);
            }
            //std::cout << std::endl;
            this->tiles.push_back(row);
        }
    }

    void Map::load(std::string name){
        std::ifstream content(("Resources/" + name + ".csv").c_str());
        std::string line;
        while (std::getline(content, line)){
            std::vector<int> row;
            std::istringstream data(line);
            int i;
            char c;
            while (data >> i){
                row.push_back(i);
                data >> c;
            }
            tiles.push_back(row);
        }
    }

    int Map::tileAt(int x, int y){
        return tiles[y][x];
    }

    int Map::width(){
        return tiles[0].size();
    }

    int Map::height(){
        return tiles.size();
    }
}

