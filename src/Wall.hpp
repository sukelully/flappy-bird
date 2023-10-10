#ifndef Wall_hpp
#define Wall_hpp

#include <stdio.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Wall {
    float topSize;
    float bottomSize;
    
public:
    sf::RectangleShape top;
    sf::RectangleShape bottom;
    
    Wall();
    void initWall();
//    void update();
};

#endif
