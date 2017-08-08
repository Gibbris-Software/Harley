#ifndef __NPC_H_
#define __NPC_H_

#include "sfml.h"

namespace Harley {

    class NPC
    {
        public:
            NPC(std::string);
            virtual ~NPC();
        protected:
        private:
            std::string name;
            sf::Texture texture;
            sf::Sprite sprite;
            // std::map<int, std::tuple<int[2], std::vector<int> > > paths;
    };
}

#endif // __NPC_H_
