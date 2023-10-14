#include "Game.hpp"

const int win_width = 800;
const int win_height = 600;
int wallCounter = 0;

/*
 To do:
 - Randomise wall hole size.
 - Gradual wall speed increase.
 - Score system.
 - Object intersection.
 - Clean up / comment.
 - Put private/public functions in the correct place.
 */


void Game::initVariables() { 
    this->window = nullptr;
    this->isOver = false;
}

void Game::initWindow() {
    this->videoMode.width = win_width;
    this->videoMode.height = win_height;
    
    this->window = new sf::RenderWindow(this->videoMode, "Flappy Bird",
                                            sf::Style::Titlebar | sf::Style::Close);
    
    this->window->setFramerateLimit(60);
}

Game::Game() {
    this->initVariables();
    bird.initBird();
    this->createWall();
    this->initWindow();
}

Game::~Game() {
    delete this->window;
}

void Game::pollEvents() {
    // Handle all events.
    while (this->window-> pollEvent(this->event)) {
        switch (this->event.type) {
            case sf::Event::Closed:
                this->window->close();
                break;
            case sf::Event::KeyPressed:
                if (this->event.key.code == sf::Keyboard::Escape)
                    this->window->close();
                if (this->event.key.code == sf::Keyboard::Space)
                    bird.jump();
                break;
        }
    }
}

const bool Game::isRunning() const {
    return this->window->isOpen();
}

void Game::collision(sf::CircleShape bird, sf::RectangleShape top, sf::RectangleShape bottom) {
    if (bird.getGlobalBounds().intersects(top.getGlobalBounds()) || bird.getGlobalBounds().intersects(bottom.getGlobalBounds())) {
        gameOver();
    }
}

void Game::update() {
    this->pollEvents();
    
    if (!isOver) {
        this->updateBird();
        this->updateWalls();
    }
}

void Game::createWall() {
    wall.initWall();
    
    this->walls.push_back(this->wall);
}

void Game::updateBird() {
    if (this->bird.getPosition().y > this->window->getSize().y) {
        this->gameOver();
    }
    bird.update();
}

void Game::gameOver() {
    std::cout << "You're out!" << std::endl;
    isOver = true;
}

// Move and create walls. Detect collisions with birds. Update score.
void Game::updateWalls() {
    for (int i = 0; i < this->walls.size(); i++) {
        
        // Create new wall when previous reaches x = 500.
        if (this->walls[wallCounter].top.getPosition().x < 500) {
            this->createWall();
            wallCounter += 1;
        }
        
        // Update score.
        if (this->walls[wallCounter-1].top.getPosition().x < win_width/2) {
            std::cout << "Score = " << wallCounter << std::endl;
        }
        
        // Detect collisions.
        collision(bird, walls[i].top, walls[i].bottom);
        
        // Move walls right to left.
        this->walls[i].top.move(-2.f, 0.f);
        this->walls[i].bottom.move(-2.f, 0.f);
        
        // Delete off-screen walls from memory.
        if (this->walls[i].top.getPosition().x > this->window->getSize().x) {
            this->walls.erase(this->walls.begin() + i);
        }
    }
}

void Game::render() {
    this->window->clear(sf::Color(20, 20, 20));
    
    // Draw game objects.
    this->window->draw(bird);
    this->renderWalls();
    this->window->display();
}

void Game::renderWalls() {
    for (auto &w : this->walls) {
        this->window->draw(w.top);
        this->window->draw(w.bottom);
    }
}
