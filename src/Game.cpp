#include "Game.hpp"

const int win_width = 800;
const int win_height = 600;


void Game::initVariables() { 
    this->window = nullptr;
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
//    wall.initWall();
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

void Game::update() {
    this->pollEvents();
//    this->getMousePosition();
//    this->updateMousePositions();
    bird.update();
//    wall.update();
    this->updateWalls();
}

void Game::createWall() {
    wall.initWall();
    
    this->walls.push_back(this->wall);
}

void Game::updateWalls() {
    std::cout << this->wall.top.getPosition().x << std::endl;
    if (this->wall.top.getPosition().x < 500) {
        this->createWall();
    }
    
    for (int i = 0; i < this->walls.size(); i++) {
        bool deleted = false;
        this->walls[i].top.move(-2.f, 0.f);
        this->walls[i].bottom.move(-2.f, 0.f);
        
        if (this->walls[i].top.getPosition().x > this->window->getSize().x) {
            deleted = true;
        }
        
        if (deleted) this->walls.erase(this->walls.begin() + i);
    }
}

void Game::render() {
    this->window->clear(sf::Color(20, 20, 20));
    
    // Draw game objects.
    this->window->draw(bird);
//    this->window->draw(wall.top);
//    this->window->draw(wall.bottom);
//    this->window->draw(wall);
    this->renderWalls();
    this->window->display();
}

void Game::renderWalls() {
    for (auto &w : this->walls) {
        this->window->draw(w.top);
        this->window->draw(w.bottom);
    }
}

void Game::getMousePosition() {
    // Mouse position relative to window.
    std::cout << "Mouse pos: "
    << sf::Mouse::getPosition(*this->window).x << ", "
    << sf::Mouse::getPosition(*this->window).y << std::endl;;
}

void Game::updateMousePositions() {
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
    this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}
