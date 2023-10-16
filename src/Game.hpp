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
public:
    Game();
    ~Game();
    void run();
    
    const bool isRunning();
    
private:
    // Member variables.
    sf::RenderWindow window;
    Bird bird;
    Wall wall;
    std::vector<Wall> walls;
    
    sf::Font font;
    sf::Text score;
    sf::Text startMessage;
    sf::RectangleShape startTile;
    
    bool isOver;
    bool gameStarted;
    int wallCounter;
    float wallSpeed;
    
    // Private member functions.
    void initialise();
    void handleEvents();
    void update();
    void updateBird();
    void updateWalls();
    void render();
    void createWall();
    void gameOver();
    void startGame();
    void centreText(sf::Text& text);
    void collision(sf::CircleShape bird, sf::RectangleShape top, sf::RectangleShape bottom);
};

#endif
