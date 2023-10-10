#include "Bird.hpp"

const int win_width = 800;
const int win_height = 600;

Bird::Bird() {
    vel.y = 1;
}

void Bird::initBird() {
    Bird();
    this->setPosition(win_width/2, win_height/2);
    this->setRadius(10);
    this->setFillColor(sf::Color::Green);
}

void Bird::update() {
    this->move(vel);
    vel.y += 1;
    
    if (vel.y >= 10) {
        vel.y = 10;
    }
}

void Bird::jump() {
    vel.y = -15;
}
