#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <ctime>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "Bird.hpp"
#include "Wall.hpp"
    
class Game {
    // Window.
    sf::RenderWindow* window;
    sf::VideoMode videoMode;
    sf::Event event;
    
    // Game objects.
    Bird bird;
    Wall wall;
    std::vector<Wall> walls;
    
    // Mouse positions.
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;

    // Private functions.
    void initVariables();
    void initWindow();
    void getMousePosition();
    
public:
    // Constructors.
    Game();
    virtual ~Game();
    
    // Accessors.
    const bool isRunning() const;
    
    // Functions.
    void pollEvents();
    void update();
    void render();
    void renderWalls();
    void createWall();
    void updateWalls();
    void updateMousePositions();
};

#endif
