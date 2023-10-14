#include "Wall.hpp"

const int win_width = 800;
const int win_height = 600;

void Wall::initWall() {
    topSize = static_cast<float>( rand() % static_cast<int>(400 - 100 + 1) + 100);
    bottomSize = (win_height - topSize - 200) * -1;
    
    top.setSize(sf::Vector2f(10, topSize));
    top.setPosition(win_width, 0);
    top.setFillColor(sf::Color::Red);
    bottom.setSize(sf::Vector2f(10, bottomSize));
    bottom.setPosition(win_width, win_height);
    bottom.setFillColor(sf::Color::Red);
}
