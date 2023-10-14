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
    sf::Font font;
    sf::RectangleShape startTile;
    sf::Text startMessage;
    
    // Game logic variables.
    bool isOver;

    // Initialisation.
    void initVariables();
    void initWindow();
    void initScore();
    void initStartScreen();
    void initGame();
    
    // Updating.
    void updateScore();
    void updateWalls();
    void updateBird();
    
    // Rendering.
    void renderWalls();
    void createWall();
    void gameOver();
    
    // Game logic function.
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
