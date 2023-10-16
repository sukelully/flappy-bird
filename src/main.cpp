#include <iostream>
#include "Game.hpp"

int main() {
    // Init srand.
    std::srand(static_cast<unsigned>(time(NULL)));
    
    // Init game engine.
    Game game;
    
    // Game loop.
    game.run();
    
    return 0;
}
