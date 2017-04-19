#ifndef __MAP_H_
#define __MAP_H_

#include <vector>
#include <string>

namespace Harley {
    class Map {
        std::vector<std::vector<int> > tiles;
      public:
        Map(std::string);
        int tileAt(int, int);
    };
}

#endif // __MAP_H_
