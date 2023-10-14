#include "Wall.hpp"

const int win_width = 800;
const int win_height = 600;
const int wall_width = 20;
const sf::Color wall_color = sf::Color(2, 107, 11);

// Initialise a new wall section with random top/bottom sizes.
void Wall::initWall() {
    topSize = static_cast<float>( rand() % static_cast<int>(400 - 100 + 1) + 100);
    bottomSize = (win_height - topSize - 200) * -1;
    
    top.setSize(sf::Vector2f(wall_width, topSize));
    top.setPosition(win_width, 0);
    top.setFillColor(wall_color);
    
    bottom.setSize(sf::Vector2f(wall_width, bottomSize));
    bottom.setPosition(win_width, win_height);
    bottom.setFillColor(wall_color);
}
