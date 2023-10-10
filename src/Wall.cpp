#include "Wall.hpp"

const int win_width = 800;
const int win_height = 600;

Wall::Wall() {
    
}

void Wall::drawWall() {
    top.setSize(sf::Vector2f(10, 250));
    top.setPosition(win_width, 0);
    top.setFillColor(sf::Color::Red);
    bottom.setSize(sf::Vector2f(10, -250));
    bottom.setPosition(win_width, win_height);
    bottom.setFillColor(sf::Color::Red);
}

//void Wall::initWall(int x, int y) {
//    wall.setPosition(x, y);
//    wall.setSize(sf::Vector2f(10, 200));
//    wall.setFillColor(sf::Color::Red);
//}

void Wall::update() {
    top.move(-1, 0);
    bottom.move(-1, 0);
}
