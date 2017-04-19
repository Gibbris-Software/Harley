#include <string>
#include <fstream>
#include <sstream>
#include "map.h"

namespace Harley
{
	Map::Map (std::string name)
    {
        std::ifstream content(name.c_str());
        std::string line;
        while (std::getline(content, line)){
            std::vector<int> row;
            std::istringstream data(line);
            int i;
            char x;
            while (data >> i >> x){
                row.push_back(i);
            }
            tiles.push_back(row);
        }
    }

    int Map::tileAt(int x, int y){
        return tiles[y][x];
    }
}

