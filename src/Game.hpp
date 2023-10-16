#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "Bird.hpp"
#include "Wall.hpp"
    
class Game {
    // Constants and global variables.
    const int win_width = 800;
    const int win_height = 600;
    int wallCounter = 0;
    int startButton = 0;
    float wallSpeed = -2;
    
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
    void centreText(sf::Text &text);
    
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
