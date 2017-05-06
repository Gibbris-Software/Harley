#ifndef __MAP_H_
#define __MAP_H_

#include <vector>
#include <string>

namespace Harley {
    class Map {
        std::vector<std::vector<int> > tiles;
      public:
        Map(std::string);
        Map(std::string, int, int, int, int);
        int tileAt(int, int);
        int width();
        int height();
    };
}

#endif // __MAP_H_
