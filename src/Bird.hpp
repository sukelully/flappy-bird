#ifndef Bird_hpp
#define Bird_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

class Bird : public sf::CircleShape {
public:
    Bird();
    void initBird();
};

#endif
