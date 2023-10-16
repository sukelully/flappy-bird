#include "Game.hpp"

/*
 To do:
 - Randomise wall hole size.
 - Score system.
 - Clean up / comment.
 - Add sprites, spruce up color scheme.
 */

// Constructor. Initalise variables and start message.
Game::Game() {
    this->initVariables();
    this->initScore();
    this->initStartScreen();
    this->initWindow();
}

// Deconstructor.
Game::~Game() {
    delete this->window;
}

// Handle all events.
void Game::pollEvents() {
    while (this->window-> pollEvent(this->event)) {
        switch (this->event.type) {
            case sf::Event::Closed:
                this->window->close();
                break;
            case sf::Event::KeyPressed:
                // Close game if Escape key is pressed.
                if (this->event.key.code == sf::Keyboard::Escape)
                    this->window->close();
                if (this->event.key.code == sf::Keyboard::Space)
                    // Spacebar causes bird to jump after initial press.
                    if (startButton != 0) {
                        bird.jump();
                    // Initial press starts the game.
                    } else if (startButton == 0) {
                        initGame();
                        startButton++;
                    }
                break;
        }
    }
}

// Update game objects if "isOver" is false.
void Game::update() {
    this->pollEvents();
    
    // When the bird collides or falls out of bounds, the game ends.
    if (!isOver) {
        this->updateBird();
        this->updateWalls();
    }
}

// Draw and color game objects.
void Game::render() {
    this->window->clear(sf::Color(105, 161, 250));
    
    // Draw game objects.
    this->window->draw(startTile);
    this->window->draw(startMessage);
    this->window->draw(bird);
    this->renderWalls();
    this->window->draw(score);
    this->window->display();
}

// Draw top and bottom wall pieces.
void Game::renderWalls() {
    for (auto &w : this->walls) {
        this->window->draw(w.top);
        this->window->draw(w.bottom);
    }
}

// Create a wall section and add it to the walls vector.
void Game::createWall() {
    wall.initWall();
    this->walls.push_back(this->wall);
}

// Initialise game variables.
void Game::initVariables() {
    this->window = nullptr;
    this->isOver = false;
}

// Initialise game window and set frame rate.
void Game::initWindow() {
    this->videoMode.width = win_width;
    this->videoMode.height = win_height;
    
    this->window = new sf::RenderWindow(this->videoMode, "Flappy Bird", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(60);
}

// Initialise score.
void Game::initScore() {
    score.setFont(font);
    score.setFillColor(sf::Color::White);
    score.setCharacterSize(50);
}

// Initialises bird and first wall, removes start menu.
void Game::initGame() {
    bird.initBird();
    this->createWall();
    startTile.setFillColor(sf::Color::Transparent);
    startMessage.setFillColor(sf::Color::Transparent);
}

// Create start screen message to ensure player is ready.
void Game::initStartScreen() {
    // Load font.
    if (!font.loadFromFile("media/font.ttf")) {
        std::cout << "Error loading font" << std::endl;
    }
    
    // Initialise background tile.
    startTile.setPosition(100, 100);
    startTile.setSize(sf::Vector2f(600, 400));
    startTile.setFillColor(sf::Color(66, 135, 245));
    
    // Initialise start screen message.
    startMessage.setFont(font);
    startMessage.setFillColor(sf::Color::White);
    startMessage.setString("Press spacebar to play!");
    startMessage.setCharacterSize(40);

    // Centre text and set position.
    centreText(startMessage);
    startMessage.setPosition(400, 300);
}

// Check if game window is open.
const bool Game::isRunning() const {
    return this->window->isOpen();
}

// Centre text.
void Game::centreText(sf::Text &text) {
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width/2.0f,
                   textRect.top  + textRect.height/2.0f);
}

// Detect collisions between bird and walls.
void Game::collision(sf::CircleShape bird, sf::RectangleShape top, sf::RectangleShape bottom) {
    if (bird.getGlobalBounds().intersects(top.getGlobalBounds()) ||
        bird.getGlobalBounds().intersects(bottom.getGlobalBounds())) {
        gameOver();
    }
}

// Move bird and checks if bird is within the screen window.
void Game::updateBird() {
    if (startButton != 0) {
        if (this->bird.getPosition().y > this->window->getSize().y) {
            this->gameOver();
            std::cout << "Error?" << std::endl;
        }
        bird.update();
    }
}

// Set boolean variable to true to stop game from updating.
void Game::gameOver() {
    std::cout << "You're out!" << std::endl;
    isOver = true;
}

// Spawn new walls and move them. Detect collisions with birds. Update score.
void Game::updateWalls() {
    for (int i = 0; i < this->walls.size(); i++) {
        
        // Create new wall when previous reaches x = 460.
        if (this->walls[wallCounter].top.getPosition().x < 460) {
            this->createWall();
            wallCounter += 1;
        }
        
        // Update score.
        if (this->walls[wallCounter-1].top.getPosition().x < win_width/2) {
            score.setString(std::to_string(wallCounter));
            centreText(score);
            score.setPosition(400, 40);
        }
        
        // Detect collisions.
        collision(bird, walls[i].top, walls[i].bottom);
        
        // Move walls right to left.
        this->walls[i].top.move(wallSpeed, 0.f);
        this->walls[i].bottom.move(wallSpeed, 0.f);
        
        // Delete off-screen walls from memory.
        if (this->walls[i].top.getPosition().x > this->window->getSize().x) {
            this->walls.erase(this->walls.begin() + i);
        }
    }
    
    // Gradually speed up walls.
    wallSpeed -= 0.001;
}
