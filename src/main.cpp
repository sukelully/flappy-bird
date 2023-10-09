#include <iostream>
#include "Game.hpp"

int main() {
    // Init srand.
    std::srand(static_cast<unsigned>(time(NULL)));
    
    // Init game engine.
    Game game;
    
    // Game loop.
    while (game.isRunning()) {
        // Update game.
        game.update();
        
        // Render.
        game.render();
    }
    
    return 0;
}
