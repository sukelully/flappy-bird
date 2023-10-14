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
    sf::Text score;
    
    // Game logic.
    bool isOver;

    // Private functions.
    void initVariables();
    void initWindow();
    void initScore();
    void updateScore();
    void renderWalls();
    void createWall();
    void updateWalls();
    void updateBird();
    void gameOver();
    void collision(sf::CircleShape bird, sf::RectangleShape top, sf::RectangleShape bottom);
    void pollEvents();
    
public:
    // Constructors.
    Game();
    virtual ~Game();
    
    // Accessors.
    const bool isRunning() const;
    
    // Functions.
    void update();
    void render();
};

#endif
