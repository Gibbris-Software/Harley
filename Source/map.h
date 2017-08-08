#ifndef MAP_H
#define MAP_H

#include <vector>
#include <string>

#include "possum/possum.h"

namespace Harley {
    class Map {
        Map(){};
      public:
        static void load(possum::Entity&, std::string);
        static void load_chunks(possum::Entity&, std::string, int, int, int, int);
    };
}

#endif // __MAP_H_
