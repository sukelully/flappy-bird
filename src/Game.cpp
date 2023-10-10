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
}

void Game::render() {
    this->window->clear(sf::Color(20, 20, 20));
    
    // Draw game objects.
    this->window->draw(bird);
    this->window->display();
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
