#include "Bird.hpp"

const int win_width = 800;
const int win_height = 600;

Bird::Bird() {
    
}

void Bird::initBird() {
    Bird();
    this->setPosition(win_width/2, win_height/2);
    this->setRadius(10);
    this->setFillColor(sf::Color::Green);
}
