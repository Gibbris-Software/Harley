#include "npc.h"

#include <fstream>

namespace Harley {
    NPC::NPC(std::string name)
    {
        std::ifstream content(("Resources/" + name + ".npc").c_str());

    }

    NPC::~NPC()
    {
        //dtor
    }

}
