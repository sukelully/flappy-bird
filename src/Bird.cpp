#include "Bird.hpp"

const int win_width = 800;
const int win_height = 600;

// Initialises bird size, color and position.
void Bird::initBird() {
    this->setPosition(win_width/2, 100);
    this->setRadius(10);
    this->setFillColor(sf::Color(247, 207, 96));
}

// Updates bird position. Bird is constantly falling downwards until jump() is executed.
void Bird::update() {
    this->move(vel);
    
    // Constant downward acceleration to simulate gravity.
    vel.y += 1;
    
    // Caps gravity at 10.
    if (vel.y >= 10) {
        vel.y = 10;
    }
}

// Bird "jumps" by adding an upwards velocity of 13 when spacebar is pressed.
void Bird::jump() {
    vel.y = -13;
}
