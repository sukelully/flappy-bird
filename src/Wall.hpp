#ifndef Wall_hpp
#define Wall_hpp

#include <stdio.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Wall {
    
public:
    sf::RectangleShape top;
    sf::RectangleShape bottom;
    
    Wall();
    void initWall(int x, int y);
    void drawWall();
    void update();
};

#endif
