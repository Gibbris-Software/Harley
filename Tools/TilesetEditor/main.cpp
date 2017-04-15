#include <string>
#include <vector>

#include <SDL2/SDL.h>

#include "editor.h"


int main(int argc, char* argv[]){
    Editor window;
    std::vector<std::string> args(argv+1, argv+argc);
    window.setup(args);
    int value = window.run();
    window.cleanup();
    return value;
}
