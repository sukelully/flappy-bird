#ifndef Bird_hpp
#define Bird_hpp

#include <stdio.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Bird : public sf::CircleShape {
    sf::Vector2f vel;
    
public:
    Bird();
    void initBird();
    void update();
    void jump();
};

#endif
