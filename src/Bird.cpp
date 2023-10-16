#include "Bird.hpp"

// Initialises bird size, color and position.
void Bird::initBird() {
    this->setPosition(392, 100);
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

// Bird jumps a small distance vertically up when spacebar is pressed.
void Bird::jump() {
    vel.y = -13;
}
